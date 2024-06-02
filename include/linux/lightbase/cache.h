#pragma once

#define LB_SYM_L1_CACHE_SIZE 256
#define LB_SYM_L2_CACHE_SIZE 1024

#define LB_SYM_CACHE_OP_NUM 8

struct sym_cache {
	const char *sym;
	void *addr;
	long long count;
};

#ifdef __cplusplus
extern "C" {
#endif

void *lb_sym_cache_find(const char *in_sym);
int lb_sym_cache_add(const char *in_sym, void *in_addr);

#ifdef __cplusplus
}
#endif