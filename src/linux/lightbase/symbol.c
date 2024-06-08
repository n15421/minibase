#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dlfcn.h>
#include <elf.h>

#include <universal/lightbase/symbol.h>
#include <universal/lightbase/cache.h>

void *g_rva_base_addr;

Elf64_Shdr g_lb_sec_tab_sym;
Elf64_Shdr g_lb_sec_tab_sym_str;

Elf64_Sym *g_lb_sym_tab;
const char *g_lb_sym_str_tab;
int g_lb_sym_nums;

void get_base_addr()
{
	long long addr = 0;
	char str_addr[13];

	str_addr[12] = 0;

	FILE *f = fopen("/proc/self/maps", "rb");
	fread(str_addr, 12, 1, f);
	fclose(f);
	sscanf(str_addr, "%llx", &g_rva_base_addr);

	printf("[LightBase] [INFO] Base addr: %p\n", g_rva_base_addr);
}

int lb_load_symbols(const char *in_filename)
{
	get_base_addr();

	FILE *bds_elf = fopen("bedrock_server_symbols.debug", "rb");
	if (!bds_elf) {
		printf("[LightBase] [ERROR] Failed to open bedrock_server_symbols.debug: %s.\n", strerror(errno));

		return -1;
	}

	Elf64_Ehdr elf_header;
	unsigned char elf_ident[4] = { 0x7f, 'E', 'L', 'F' };

	fseek(bds_elf, 0, SEEK_SET);
	fread((void *)&elf_header, sizeof(Elf64_Ehdr), 1, bds_elf);

	if (memcmp(elf_header.e_ident, elf_ident, 4)) {
		printf("[LightBase] [Error] Not a ELF file!\n");

		return -1;
	}

	Elf64_Shdr *sec_tab = (Elf64_Shdr *)malloc(elf_header.e_shnum * elf_header.e_shentsize);
	if (!sec_tab) {
		printf("[LightBase] [Error] sym str tab failed!\n");

		return -1;
	}

	fseek(bds_elf, elf_header.e_shoff, SEEK_SET);
	fread((void *)sec_tab, sizeof(Elf64_Shdr), elf_header.e_shnum, bds_elf);

	for (int i = 0; i < elf_header.e_shnum; i++) {
		if (sec_tab[i].sh_type == SHT_SYMTAB) {
			memcpy((void *)&g_lb_sec_tab_sym, (void *)&sec_tab[i], sizeof(Elf64_Shdr));
			memcpy((void *)&g_lb_sec_tab_sym_str, (void *)&sec_tab[sec_tab[i].sh_link], sizeof(Elf64_Shdr));
			break;
		}
	}

	free(sec_tab);

	fseek(bds_elf, g_lb_sec_tab_sym.sh_offset, SEEK_SET);
	g_lb_sym_tab = (Elf64_Sym *)malloc(g_lb_sec_tab_sym.sh_size);
	if (!g_lb_sym_tab) {
		printf("[LightBase] [Error] sym tab failed!\n");

		return -1;
	}

	fread((void *)g_lb_sym_tab, g_lb_sec_tab_sym.sh_size, 1, bds_elf);

	fseek(bds_elf, g_lb_sec_tab_sym_str.sh_offset, SEEK_SET);
	g_lb_sym_str_tab = (const char *)malloc(g_lb_sec_tab_sym_str.sh_size);
	if (!g_lb_sym_str_tab) {
		printf("[LightBase] [Error] sym str tab failed!\n");

		return -1;
	}
	fread((void *)g_lb_sym_str_tab, g_lb_sec_tab_sym_str.sh_size, 1, bds_elf);

	fclose(bds_elf);

	g_lb_sym_nums = g_lb_sec_tab_sym.sh_size / g_lb_sec_tab_sym.sh_entsize;

	printf("[LightBase] [INFO] Loaded %d symbol(s)\n", g_lb_sym_nums);
}

void *lb_sym_find(const char *in_sym)
{
	void *addr = dlsym(NULL, in_sym);
	if (!addr) {
		printf("[LightBase] [DEBUG] Symbol not found in dynsym: %s.\n", in_sym);

		for (int i = 0; i < g_lb_sym_nums; i++) {
			if (!strcmp(in_sym, g_lb_sym_str_tab + g_lb_sym_tab[i].st_name)) {
				addr = (void *)(g_rva_base_addr + g_lb_sym_tab[i].st_value);
			}
		}

		if (!addr) {
			printf("[LightBase] [ERROR] Symbol not found: %s.\n", in_sym);

			return NULL;
		}
	}

	return addr;
}

void *lb_sym_call_find(const char *in_sym)
{
	void *addr = lb_sym_cache_find(in_sym);
	if (!addr) {
		printf("[LightBase] [DEBUG] Symbol not found in cache: %s.\n", in_sym);

		addr = lb_sym_find(in_sym);
		if (addr) {
			lb_sym_cache_add(in_sym, addr);
		}
	}

	return addr;
}
