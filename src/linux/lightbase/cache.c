#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <universal/lightbase/cache.h>

struct sym_cache g_lb_sym_l1_cache_tab[LB_SYM_L1_CACHE_SIZE];
struct sym_cache g_lb_sym_l2_cache_tab[LB_SYM_L2_CACHE_SIZE];

int g_lb_sym_l1_cache_tab_count = 0;
int g_lb_sym_l2_cache_tab_count = 0;

int cache_qsort(struct sym_cache *in_p1, struct sym_cache *in_p2)
{
	if (in_p1->count > in_p2->count) {
		return -1;
	}

	if (in_p1->count < in_p2->count) {
		return 1;
	}

	return 0;
}

void *lb_sym_l1_cache_find(const char *in_sym)
{
	for (int i = 0; i < g_lb_sym_l1_cache_tab_count; i++) {
		if (!strcmp(g_lb_sym_l1_cache_tab[i].sym, in_sym)) {
			printf("[LightBase] [DEBUG] L1 Cache hit!: %s.\n", in_sym);

			g_lb_sym_l1_cache_tab[i].count++;
			return g_lb_sym_l1_cache_tab[i].addr;
		}
	}

	return NULL;
}
void *lb_sym_l2_cache_find(const char *in_sym)
{
	for (int i = 0; i < g_lb_sym_l2_cache_tab_count; i++) {
		if (!strcmp(g_lb_sym_l2_cache_tab[i].sym, in_sym)) {
			printf("[LightBase] [DEBUG] L2 Cache hit!: %s.\n", in_sym);

			g_lb_sym_l2_cache_tab[i].count++;
			return g_lb_sym_l2_cache_tab[i].addr;
		}
	}

	return NULL;
}

void *lb_sym_cache_find(const char *in_sym)
{
	void *addr = lb_sym_l1_cache_find(in_sym);
	if (!addr) {
		addr = lb_sym_l2_cache_find(in_sym);
	}

	return addr;
}

int lb_sym_l1_cache_add(const char *in_sym, void *in_addr)
{
	if (g_lb_sym_l1_cache_tab_count < LB_SYM_L1_CACHE_SIZE - 1) {
		g_lb_sym_l1_cache_tab[g_lb_sym_l1_cache_tab_count].sym = in_sym;
		g_lb_sym_l1_cache_tab[g_lb_sym_l1_cache_tab_count].addr = in_addr;
		g_lb_sym_l1_cache_tab[g_lb_sym_l1_cache_tab_count].count = 1;

		g_lb_sym_l1_cache_tab_count++;

		printf("[LightBase] [DEBUG] L1 Cache add!: %s.\n", in_sym);

		return 0;
	} else {
		printf("[LightBase] [DEBUG] L1 Cache full!: %s.\n", in_sym);

		return -1;
	}

	return 0;
}

int lb_sym_l2_cache_add(const char *in_sym, void *in_addr)
{
	if (g_lb_sym_l2_cache_tab_count < LB_SYM_L2_CACHE_SIZE - 1) {
		g_lb_sym_l2_cache_tab[g_lb_sym_l2_cache_tab_count].sym = in_sym;
		g_lb_sym_l2_cache_tab[g_lb_sym_l2_cache_tab_count].addr = in_addr;
		g_lb_sym_l2_cache_tab[g_lb_sym_l2_cache_tab_count].count = 1;

		g_lb_sym_l2_cache_tab_count++;

		printf("[LightBase] [DEBUG] L2 Cache add!: %s.\n", in_sym);

		return 0;
	} else {
		printf("[LightBase] [DEBUG] L2 Cache full!: %s.\n", in_sym);

		return -1;
	}

	return 0;
}

void sym_cache_count_reset()
{
	// for (int i = 0)
}

void sym_cache_downgrade()
{
	printf("[LightBase] [DEBUG] Cache downgrade!\n");

	qsort((void *)g_lb_sym_l1_cache_tab, g_lb_sym_l1_cache_tab_count, sizeof(struct sym_cache), (__compar_fn_t)cache_qsort);
	qsort((void *)g_lb_sym_l2_cache_tab, g_lb_sym_l2_cache_tab_count, sizeof(struct sym_cache), (__compar_fn_t)cache_qsort);

	// for (int i = g_lb_sym_l2_cache_tab_count - LB_SYM_CACHE_OP_NUM; i < g_lb_sym_l2_cache_tab_count; i++) {
	// 	memset((void *)&g_lb_sym_l2_cache_tab[i], 0, sizeof(g_lb_sym_l2_cache_tab[i]));
	// }

	g_lb_sym_l2_cache_tab_count -= LB_SYM_CACHE_OP_NUM;

	for (int i = g_lb_sym_l1_cache_tab_count - LB_SYM_CACHE_OP_NUM; i < g_lb_sym_l1_cache_tab_count; i++) {
		lb_sym_l2_cache_add(g_lb_sym_l1_cache_tab[i].sym, g_lb_sym_l1_cache_tab[i].addr);
		// memset((void *)&g_lb_sym_l1_cache_tab[i], 0, sizeof(g_lb_sym_l1_cache_tab[i]));
	}

	g_lb_sym_l1_cache_tab_count -= LB_SYM_CACHE_OP_NUM;
}

int lb_sym_cache_add(const char *in_sym, void *in_addr)
{
	int ret = lb_sym_l1_cache_add(in_sym, in_addr);
	if (ret) {
		sym_cache_downgrade();
		ret = lb_sym_l1_cache_add(in_sym, in_addr);
	}

	return 0;
}
