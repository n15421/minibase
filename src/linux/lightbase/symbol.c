#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dlfcn.h>
#include <elf.h>

#include <universal/uthash/uthash.h>

#include <universal/lightbase/lightbase.h>
#include <universal/lightbase/symbol.h>

struct s_sym_hashmap {
	const char *sym;
	void *addr;
	UT_hash_handle hh;
};

struct s_sym_hashmap *g_sym_map = NULL;
struct s_sym_hashmap *g_sym_key = NULL;

int lb_load_symbols(const char *in_filename)
{
	char *rva_base_addr;

	char str_addr[13];
	str_addr[12] = 0;

	FILE *f = fopen("/proc/self/maps", "rb");
	fread(str_addr, 12, 1, f);
	fclose(f);
	sscanf(str_addr, "%p", &rva_base_addr);

	lb_preinit_logger(LEVEL_DEBUG, "Base addr: %p\n", rva_base_addr);

	Elf64_Shdr sec_tab_sym;
	Elf64_Shdr sec_tab_sym_str;

	FILE *bds_elf = fopen("bedrock_server_symbols.debug", "rb");
	if (!bds_elf) {
		lb_preinit_logger(LEVEL_ERROR, "Failed to open bedrock_server_symbols.debug: %s.\n", strerror(errno));

		return -1;
	}

	Elf64_Ehdr elf_header;
	unsigned char elf_ident[4] = { 0x7f, 'E', 'L', 'F' };

	fseek(bds_elf, 0, SEEK_SET);
	fread((void *)&elf_header, sizeof(Elf64_Ehdr), 1, bds_elf);
	if (memcmp(elf_header.e_ident, elf_ident, 4)) {
		lb_preinit_logger(LEVEL_ERROR, "Not a ELF file!\n");

		fclose(bds_elf);
		return -1;
	}

	Elf64_Shdr *sec_tab = (Elf64_Shdr *)malloc(elf_header.e_shnum * elf_header.e_shentsize);
	if (!sec_tab) {
		lb_preinit_logger(LEVEL_ERROR, "sym str tab failed!\n");

		fclose(bds_elf);
		return -1;
	}

	fseek(bds_elf, elf_header.e_shoff, SEEK_SET);
	fread((void *)sec_tab, sizeof(Elf64_Shdr), elf_header.e_shnum, bds_elf);

	char sym_tab_found = 0;
	for (int i = 0; i < elf_header.e_shnum; i++) {
		if (sec_tab[i].sh_type == SHT_SYMTAB) {
			memcpy((void *)&sec_tab_sym, (void *)&sec_tab[i], sizeof(Elf64_Shdr));
			memcpy((void *)&sec_tab_sym_str, (void *)&sec_tab[sec_tab[i].sh_link], sizeof(Elf64_Shdr));

			sym_tab_found = 1;
			break;
		}
	}

	free((void *)sec_tab);

	if (!sym_tab_found) {
		lb_preinit_logger(LEVEL_ERROR, "alloc sym str tab failed!\n");

		fclose(bds_elf);
		return -1;
	}

	Elf64_Sym *sym_tab;
	const char *sym_str_tab;

	fseek(bds_elf, sec_tab_sym.sh_offset, SEEK_SET);
	sym_tab = (Elf64_Sym *)malloc(sec_tab_sym.sh_size);
	if (!sym_tab) {
		lb_preinit_logger(LEVEL_ERROR, "alloc sym tab failed!\n");

		fclose(bds_elf);
		return -1;
	}
	fread((void *)sym_tab, sec_tab_sym.sh_size, 1, bds_elf);

	fseek(bds_elf, sec_tab_sym_str.sh_offset, SEEK_SET);
	sym_str_tab = (const char *)malloc(sec_tab_sym_str.sh_size);
	if (!sym_str_tab) {
		lb_preinit_logger(LEVEL_ERROR, "alloc sym str tab failed!\n");

		free(sym_tab);
		fclose(bds_elf);
		return -1;
	}
	fread((void *)sym_str_tab, sec_tab_sym_str.sh_size, 1, bds_elf);

	fclose(bds_elf);

	int sym_tab_count = sec_tab_sym.sh_size / sec_tab_sym.sh_entsize;

	int sym_count = 0;
	for (int i = 0; i < sym_tab_count; i++) {
		if ((sym_tab[i].st_info & 0xf) == STT_FUNC) {
			g_sym_key = NULL;
			HASH_FIND_STR(g_sym_map, sym_str_tab + sym_tab[i].st_name, g_sym_key);
			if (!g_sym_key) {
				g_sym_key = malloc(sizeof *g_sym_key);
				g_sym_key->sym = sym_str_tab + sym_tab[i].st_name;
				g_sym_key->addr = (void *)(rva_base_addr + sym_tab[i].st_value);
				HASH_ADD_STR(g_sym_map, sym, g_sym_key);
				sym_count++;
			}
		}
	}

	free((void *)sym_tab);

	lb_preinit_logger(LEVEL_INFO, "Loaded %d symbol(s)\n", sym_count);

	return 0;
}

void *lb_sym_find(const char *in_sym)
{
	unsigned long long prev_tsc = 0;
	unsigned long long curr_tsc = 0;

	g_sym_key = NULL;
	prev_tsc = __builtin_ia32_rdtsc();
	HASH_FIND_STR(g_sym_map, in_sym, g_sym_key);
	curr_tsc = __builtin_ia32_rdtsc();
	if (!g_sym_key) {
		lb_preinit_logger(LEVEL_DEBUG, "Symbol not found in hashmap: %s.\n", in_sym);

		return NULL;
	}

	lb_preinit_logger(LEVEL_DEBUG, "Symbol found: %s, addr: %p, time: %dns.\n", in_sym, g_sym_key->addr, (int)((curr_tsc - prev_tsc) / 3.4f));

	return g_sym_key->addr;
}
