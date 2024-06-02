#include <stdio.h>

#include <linux/lightbase/hook.h>
#include <linux/lightbase/symbol.h>
#include <linux/funchook/funchook.h>

extern long long g_lb_base_addr;

void *lb_ahook_install(void **in_target_addr, void *in_hook_addr)
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

	return *in_target_addr;
}

void *lb_shook_install(const char *in_sym, void *in_hook_addr)
{
	void *addr = lb_sym_find(in_sym);
	if (!addr) {
		printf("[LightBase] [ERROR] Symbol not found: %s.\n", in_sym);
	}

	return lb_ahook_install(&addr, in_hook_addr);
}