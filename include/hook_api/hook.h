#pragma once
#pragma comment(lib, "minhook.x64d.lib")
#include "../minhook/MinHook.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SYM_FILE "bedrock_server_sym.txt"
#define CVDUMP_URL "https://raw.github.com/microsoft/microsoft-pdb/master/cvdump/cvdump.exe"

#define TMHOOK(name, ret_type, rva_OR_sym, ...)             \
    typedef ret_type (*_##name##_t)(__VA_ARGS__);           \
    _##name##_t _original_##name = NULL;                    \
    typedef struct _##name _##name##_struct;                \
    struct _##name                                          \
    {                                                       \
        _##name##_t original;                               \
        _##name##_t detour;                                 \
        bool (*init)(_##name##_struct*);                    \
    };                                                      \
    ret_type _detour_##name(__VA_ARGS__);                   \
    bool _INIT_HOOK_##name(_##name##_struct* name)          \
    {                                                       \
        void *func_ptr = atoi(rva_OR_sym)                   \
                        ? get_rva_func(atoi(rva_OR_sym))    \
                        : get_sym_func(rva_OR_sym);         \
        _##name##_t _hook_##name =                          \
                        (_##name##_t)func_ptr;              \
        bool result = hook_func(_hook_##name,               \
                                _detour_##name,             \
                                &_original_##name);         \
        name->original = _original_##name;                  \
        name->detour = _detour_##name;                      \
        return result;                                      \
    }                                                       \
    _##name##_struct name =                                 \
    {                                                       \
        NULL,                                               \
        NULL,                                               \
        _INIT_HOOK_##name                                   \
    };                                                      \
    ret_type _detour_##name(__VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

bool hook_func(void *hook_func, void *detour_func, void *original_func);
void *get_rva_func(unsigned int rva);
void *get_sym_func(const char *sym);

#ifdef __cplusplus
}
#endif
