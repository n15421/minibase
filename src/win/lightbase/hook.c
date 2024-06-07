#include <stdio.h>

#include <universal/lightbase/hook.h>
#include <universal/lightbase/symbol.h>
#include <win/minhook/MinHook.h>

#pragma comment(linker, "/export:lb_ahook_install")
#pragma comment(linker, "/export:lb_shook_install")
#pragma comment(linker, "/export:lb_hook_uninstall")

extern long long g_lb_base_addr;

void *lb_ahook_install(void **in_target_addr, void *in_hook_addr, void **out_handle)
{
	void *ori;

	if (MH_CreateHook(*in_target_addr, in_hook_addr, &ori) != MH_OK) {
        printf("Failed to create func hook, RVA: %p \n", *in_target_addr);
        return NULL;
    }

	*out_handle = *in_target_addr;

	return ori;
}

void *lb_shook_install(const char *in_sym, void *in_hook_addr, void **out_handle)
{
	void *addr = lb_sym_find(in_sym);
	if (!addr) {
		printf("[LightBase] [ERROR] Symbol not found: %s.\n", in_sym);

		return NULL;
	}

	return lb_ahook_install(&addr, in_hook_addr, out_handle);
}

void lb_hook_uninstall(const char *in_sym, void *in_handle)
{
	int ret = 0;

	MH_RemoveHook(in_handle);
}
