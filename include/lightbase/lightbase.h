#pragma once
#pragma comment(lib, "minhook.x64.lib")
#include <minhook/MinHook.h>
#include "file_utils.h"

#ifdef LIGHTBASE_EXPORTS
#define LIGHTBASE_API __declspec(dllexport)
#else
#define LIGHTBASE_API __declspec(dllimport)
#endif
#define LBAPI LIGHTBASE_API

#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define LB_PATH "plugins\\lb\\"
#define SYM_FILE LB_PATH "symbols.txt"
#define SYM_CACHE_FILE LB_PATH "sym_cache.bin"

#define CVDUMP_URL "https://raw.github.com/microsoft/microsoft-pdb/master/cvdump/cvdump.exe"
#define CVDUMP_EXE_PATH LB_PATH "cvdump.exe"
#define CVDUMP_EXEC_ARGS " -headers -p "
#define CVDUMP_MISSING_MSG \
            CVDUMP_EXE_PATH " not found, please download it from " CVDUMP_URL \
            " and then put it in the same level folder as bedrock_server.pdb\n"

#define BDS_FILE_NAME "bedrock_server"
#define BDS_EXE_PATH BDS_FILE_NAME ".exe"
#define BDS_MOD_EXE_PATH BDS_FILE_NAME "_mod" ".exe"
#define BDS_PDB_PATH BDS_FILE_NAME ".pdb"


#define THOOK(name, ret_type, sym, ...)          		     \
    typedef ret_type (*_##name##_t)(__VA_ARGS__);            \
    ret_type _detour_##name(__VA_ARGS__);                    \
    int _install_##name(void);                               \
    bool _destroy_##name(void);                              \
                                                             \
    struct _##name {                                         \
        _##name##_t hook;                                    \
        _##name##_t detour;                                  \
        _##name##_t original;                                \
        int (*install)(void);                                \
        bool (*destroy)(void);                               \
    } name = {NULL, _detour_##name, NULL,                    \
                _install_##name, _destroy_##name};           \
                                                             \
    int _install_##name(void)                                \
    {                                                        \
        name.hook = (_##name##_t)dlsym(sym);                 \
        return hook_func(name.hook,                          \
                         name.detour,                        \
                         (void **)&name.original);           \
    }                                                        \
                                                             \
    bool _destroy_##name(void)                               \
    {                                                        \
        return unhook_func(name.hook);                       \
    }                                                        \
                                                             \
    ret_type _detour_##name(__VA_ARGS__)



#define SYMCALL(sym, func_proto, ...)                        \
    ((func_proto)                                            \
    (dlsym(sym)))                                            \
    (__VA_ARGS__)


#define PTRCALL(ptr, func_proto, ...)                       \
    ((func_proto)                                           \
    ((void *)ptr))                                          \
    (__VA_ARGS__)


#define DEREFERENCE(type, ptr, offset)                      \
    (*(type*)((uintptr_t)ptr + offset))


#define REFERENCE(type, ptr, offset)                        \
    (type*)((uintptr_t)ptr + offset)


// for uintptr_t
#define PTR_OFFSET(ptr, offset)                             \
    ((uintptr_t)ptr + offset)


#ifdef __cplusplus
extern "C" {
#endif

LBAPI bool hook_func(void *hook_func, void *detour_func, void *original_func);
LBAPI bool unhook_func(void *hook_func);
LBAPI void *rva2va(unsigned int rva);
LBAPI void read_static_data(long offset, void *data, size_t size);
LBAPI void *dlsym(const char *sym);
LBAPI bool release_cvdump_exe(void);
LBAPI int gen_sym_file(void);
LBAPI int re_gen_sym_files(void);

LBAPI bool init_section_infos(void);

LBAPI int get_network_protocol_version(void);

LBAPI void check_server_update(void);

LBAPI bool lb_init(void);
LBAPI bool lb_uninit(void);
LBAPI bool lb_enable_all_hook(void);
LBAPI bool lb_disable_all_hook(void);

#ifdef __cplusplus
}
#endif
