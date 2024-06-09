#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <windows.h>

#include <universal/uthash/uthash.h>

#include <universal/lightbase/lightbase.h>
#include <universal/lightbase/symbol.h>

#pragma comment(linker, "/export:lb_sym_find")

#define PDBV2_SIG "Microsoft C/C++ program database 2.00\r\n\032JG\0\0"
#define PDBV7_SIG "Microsoft C/C++ MSF 7.00\r\n\x1aDS"

struct s_sym_hashmap {
	const char *sym;
	void *addr;
	UT_hash_handle hh;
};

struct pdb_root_stream_map {
	unsigned int size;
	unsigned int num_of_pages;
	unsigned int *page_num_tab;
};

struct pdb_header {
	const char sig[32];
	unsigned int page_size;
	unsigned int free_block_map_block;
	unsigned int file_pages;
	unsigned int root_stream_size;
	unsigned int reserved;
	unsigned int root_stream_page_num;
};

struct pdb_sym {
	short section;
	int offset;
	int size;
	int flags;
	short module_num;
	int crc;
	int relocations_data;
};

struct pdb_stream_dbi_header {
	int sig;
	unsigned int version;
	unsigned int age;
	unsigned short global_stream_index;
	unsigned short build_number;
	unsigned short public_stream_index;
	unsigned short pdb_dll_version;
	unsigned short sym_rec_stream_index;
	unsigned short pdb_dll_rbld;
	int mod_info_size;
	int section_contribution_size;
	int section_map_size;
	int source_info_size;
	int type_server_map_size;
	unsigned int mfc_type_server_index;
	int optional_dbg_header_size;
	int ec_substream_size;
	unsigned short flags;
	unsigned short machine;
	unsigned int padding;
};

struct pdb_pub_sym_stream_sym {
	unsigned short len;
	unsigned short type;
	unsigned int reseverd;
	unsigned int offset;
	unsigned short secion_num;
	char str[];
} sub_inf;

struct s_sym_hashmap *g_sym_hashmap = NULL;
struct s_sym_hashmap *g_hashmap_sym = NULL;

char *g_sym_str_tab = 0;

void *pdb_read_stream(FILE *in_pdb_file, int in_page_size, int *in_page_num_tab, int in_size)
{
	int num_of_pages = (int)ceilf(in_size / (float)in_page_size);

	void *stream = malloc(in_size);
	if (!stream) {
		return NULL;
	}
	char *p_stream = (char *)stream;

	int stream_size = in_size;

	for (int i = 0; i < num_of_pages; i++) {
		if (stream_size >= in_page_size) {
			fseek(in_pdb_file, in_page_num_tab[i] * in_page_size, SEEK_SET);
			fread((void *)p_stream, in_page_size, 1, in_pdb_file);

			stream_size -= in_page_size;
			p_stream += in_page_size;
		} else {
			fseek(in_pdb_file, in_page_num_tab[i] * in_page_size, SEEK_SET);
			fread((void *)p_stream, stream_size, 1, in_pdb_file);
		}
	}

	return stream;
}

void *pdb_read_root_stream(FILE *in_pdb_file, int in_page_size, int in_page_num, int in_size)
{
	int num_of_pages = (int)ceilf(in_size / (float)in_page_size);
	int ctx_size = num_of_pages * 4;

	fseek(in_pdb_file, in_page_num * in_page_size, SEEK_SET);
	int *ctx = (int *)malloc(ctx_size);
	if (!ctx) { // mem alloc failed.
		return NULL;
	}
	fread(ctx, ctx_size, 1, in_pdb_file);

	void *stream = pdb_read_stream(in_pdb_file, in_page_size, ctx, in_size);

	free(ctx);

	return stream;
}

int lb_load_symbols(const char *in_filename)
{
	char *rva_base_addr = (char *)GetModuleHandle(NULL);
	rva_base_addr += *(int *)(rva_base_addr + 0x24C);

	lb_preinit_logger(LEVEL_DEBUG, "addr: %p\n", rva_base_addr);

	lb_preinit_logger(LEVEL_DEBUG, "Load sym\n");

	FILE *pdb_file = fopen(in_filename, "rb");
	if (!pdb_file) {
		lb_preinit_logger(LEVEL_ERROR, "Open bedrock_server.pdb failed.\n");

		return -1;
	}

	struct pdb_header header;
	fread((void *)&header, sizeof(header), 1, pdb_file);

	void *root_stream = pdb_read_root_stream(pdb_file, header.page_size, header.root_stream_page_num, header.root_stream_size);

	unsigned int total_streams = *(int *)root_stream;
	unsigned int *stream_size_tab = (unsigned int *)root_stream + 1;
	unsigned int *stream_page_num_tab = (unsigned int *)root_stream + 1 + total_streams;

	struct pdb_root_stream_map *stream_tab = malloc(sizeof(struct pdb_root_stream_map) * total_streams);

	for (unsigned int i = 0; i < total_streams; i++) {
		if (!stream_size_tab[i]) {
			memset((void *)&stream_tab[i], 0, sizeof(struct pdb_root_stream_map));

			continue;
		}

		if (stream_size_tab[i] == -1) {
			memset((void *)&stream_tab[i], 0, sizeof(struct pdb_root_stream_map));

			continue;
		}

		stream_tab[i].num_of_pages = (int)ceilf(stream_size_tab[i] / (float)header.page_size);
		stream_tab[i].size = stream_size_tab[i];
		stream_tab[i].page_num_tab = stream_page_num_tab;

		stream_page_num_tab += stream_tab[i].num_of_pages;
	}

	void *stream_dbi = pdb_read_stream(pdb_file, header.page_size, stream_tab[3].page_num_tab, stream_tab[3].size);

	struct pdb_stream_dbi_header *stream_dbi_header = (struct pdb_stream_dbi_header *)stream_dbi;

	void *sym_rec_stream = pdb_read_stream(pdb_file, header.page_size, stream_tab[stream_dbi_header->sym_rec_stream_index].page_num_tab, stream_tab[stream_dbi_header->sym_rec_stream_index].size);
	char *sym_rec_stream_p = (char *)sym_rec_stream;

	int sym_rec_stream_size = stream_tab[stream_dbi_header->sym_rec_stream_index].size;

	int sym_rec_nums = 0;
	for (unsigned short len; sym_rec_stream_size; sym_rec_nums++) {
		len = *(unsigned short *)sym_rec_stream_p;

		sym_rec_stream_p += 2;
		sym_rec_stream_p += len;

		sym_rec_stream_size -= 2;
		sym_rec_stream_size -= len;
	}

	struct pdb_pub_sym_stream_sym **pub_sym_tab = (struct pdb_pub_sym_stream_sym **)malloc(sizeof(struct pdb_pub_sym_stream_sym *) * sym_rec_nums);

	sym_rec_stream_size = stream_tab[stream_dbi_header->sym_rec_stream_index].size;

	sym_rec_stream_p = (char *)sym_rec_stream;

	unsigned short len;
	for (int i = 0; sym_rec_stream_size; i++) {
		pub_sym_tab[i] = (struct pdb_pub_sym_stream_sym *)sym_rec_stream_p;

		len = *(unsigned short *)sym_rec_stream_p;

		sym_rec_stream_p += 2;
		sym_rec_stream_p += len;

		sym_rec_stream_size -= 2;
		sym_rec_stream_size -= len;
	}

	int total_str_len = 0;

	for (int i = 0; i < sym_rec_nums; i++) {
		if (pub_sym_tab[i]->type == 0x110e) {
			total_str_len += (int)strlen(pub_sym_tab[i]->str) + 1;
		}
	}

	g_sym_str_tab = (char *)malloc(total_str_len);
	char *sym_str_tab_p = g_sym_str_tab;

	int sym_nums = 0;

	for (int i = 0; i < sym_rec_nums; i++) {
		if (pub_sym_tab[i]->type == 0x110e) {
			strcpy(sym_str_tab_p, pub_sym_tab[i]->str);

			g_hashmap_sym = NULL;
			HASH_FIND_STR(g_sym_hashmap, sym_str_tab_p, g_hashmap_sym);
			if (!g_hashmap_sym) {
				g_hashmap_sym = malloc(sizeof(struct s_sym_hashmap));
				g_hashmap_sym->sym = sym_str_tab_p;
				g_hashmap_sym->addr = (void *)(rva_base_addr + pub_sym_tab[i]->offset);
				HASH_ADD_STR(g_sym_hashmap, sym, g_hashmap_sym);
				sym_nums++;
			}

			sym_str_tab_p += strlen(pub_sym_tab[i]->str) + 1;
		}
	}

	lb_preinit_logger(LEVEL_DEBUG, "Free res\n");

	free(stream_tab);
	free(root_stream);
	free(stream_dbi);
	free(sym_rec_stream);
	free(pub_sym_tab);

	lb_preinit_logger(LEVEL_INFO, "Loaded %d symbol(s).\n", sym_nums);

	return 0;
}

void *lb_sym_find(const char *in_sym)
{
	DWORD64 prev_tsc = 0;
	DWORD64 curr_tsc = 0;

	g_hashmap_sym = NULL;
	prev_tsc = __rdtsc();
	HASH_FIND_STR(g_sym_hashmap, in_sym, g_hashmap_sym);
	curr_tsc = __rdtsc();
	if (!g_hashmap_sym) {
		lb_preinit_logger(LEVEL_DEBUG, "Symbol not found in hashmap: %s.\n", in_sym);

		return NULL;
	}

	lb_preinit_logger(LEVEL_DEBUG, "Symbol found: %s, addr: %p, time: %dns.\n", in_sym, g_hashmap_sym->addr, (int)((curr_tsc - prev_tsc) / 3.4f));

	return g_hashmap_sym->addr;
}

void lb_sym_free()
{
	free((void *)g_sym_str_tab);
}
