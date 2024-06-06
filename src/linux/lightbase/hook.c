#include <stdio.h>

#include <universal/lightbase/hook.h>
#include <universal/lightbase/symbol.h>
#include <linux/funchook/funchook.h>

extern long long g_lb_base_addr;

void *lb_ahook_install(void **in_target_addr, void *in_hook_addr, void **out_handle)
{
	int ret = 0;

	funchook_t *hook = funchook_create();
	if (!hook) {
		printf("Hook create failed: %s.\n", funchook_error_message(hook));
		return NULL;
	}

	ret = funchook_prepare(hook, in_target_addr, in_hook_addr);
	if (ret) {
		printf("Hook prepare failed: %s.\n", funchook_error_message(hook));
		return NULL;
	}

	ret = funchook_install(hook, 0);
	if (ret) {
		printf("Hook install failed: %s.\n", funchook_error_message(hook));
		return NULL;
	}

	*out_handle = (void *)hook;

	return *in_target_addr;
}

void *lb_shook_install(const char *in_sym, void *in_hook_addr, void **out_handle)
{
	void *addr = lb_sym_find(in_sym);
	if (!addr) {
		printf("[LightBase] [ERROR] Symbol not found: %s.\n", in_sym);
	}

	return lb_ahook_install(&addr, in_hook_addr, out_handle);
}

void lb_hook_uninstall(const char *in_sym, void *in_handle)
{
	int ret = 0;

	ret = funchook_uninstall((funchook_t *)in_handle, 0);
	if (ret) {
		printf("[LightBase] [ERROR] Hook uninstall failed: %s.\n", funchook_error_message((funchook_t *)in_handle));

		return;
	}

	ret = funchook_destroy((funchook_t *)in_handle);
	if (ret) {
		printf("[LightBase] [ERROR] Hook destory failed: %s.\n", funchook_error_message((funchook_t *)in_handle));

		return;
	}
}
