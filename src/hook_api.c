#include <hooker/hook_api.h>

bool hook_func(void *hook_func, void *detour_func, void *original_func)
{
    if (MH_CreateHook(hook_func, detour_func, (LPVOID *)original_func) != MH_OK)
    {
        printf("Failed to create func hook, RVA: %llu \n", (uintptr_t)hook_func);
        return false;
    }
    if (MH_EnableHook(hook_func) != MH_OK)
    {
        printf("Failed to enable func hook, RVA: %llu \n", (uintptr_t)hook_func);
        return false;
    }
    return true;
}

void *get_rva_func(unsigned int rva)
{
    uintptr_t base_addr = (uintptr_t)GetModuleHandle(NULL);
    return (void *)(base_addr + rva + 4096);
}
