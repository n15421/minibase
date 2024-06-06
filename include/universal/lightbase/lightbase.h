#pragma once

#include "symbol.h"

#define PLUGIN_DIR "plugins/"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __linux__
void lb_init() __attribute__((constructor));
#endif

#ifdef __cplusplus
}
#endif

#define SCALL(sym, func_proto, ...) \
	((func_proto)lb_sym_call_find(sym))(__VA_ARGS__)

#define ACALL(addr, func_proto, ...) \
	((func_proto)addr)(__VA_ARGS__)
