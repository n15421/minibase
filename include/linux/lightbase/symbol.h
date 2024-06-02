#pragma once

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int lb_load_symbols(FILE *in_file);
void *lb_sym_find(const char *in_sym);
void *lb_sym_call_find(const char *in_sym);

#ifdef __cplusplus
}
#endif