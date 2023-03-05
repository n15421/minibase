#pragma once
#pragma comment(lib, "minhook.x64d.lib")
#include "../../minhook/MinHook.h"

#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TMHOOK(name, ret_type, rva_val, ...)                \
    typedef ret_type (*name##_t)(__VA_ARGS__);              \
    name##_t original_##name = NULL;                        \
    typedef struct _##name name##_struct;                   \
    struct _##name                                          \
    {                                                       \
        name##_t original;                                  \
        name##_t detour;                                    \
        bool (*init)(name##_struct*);                       \
    };                                                      \
    ret_type detour_##name(__VA_ARGS__);                    \
    bool INIT_HOOK_##name(name##_struct* name)              \
    {                                                       \
        void *func_ptr = get_rva_func(rva_val);             \
        name##_t hook_##name =                              \
                        (name##_t)func_ptr;                 \
        bool result = hook_func(hook_##name,                \
                                detour_##name,              \
                                &original_##name);          \
        name->original = original_##name;                   \
        name->detour = detour_##name;                       \
        return result;                                      \
    }                                                       \
    name##_struct name =                                    \
    {                                                       \
        .original = NULL,                                   \
        .detour = NULL,                                     \
        .init = INIT_HOOK_##name                            \
    };                                                      \
    ret_type detour_##name(__VA_ARGS__)


bool hook_func(void *hook_func, void *detour_func, void *original_func);
void* get_rva_func(unsigned int rva);
