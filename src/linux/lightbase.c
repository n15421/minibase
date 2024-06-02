#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dlfcn.h>
#include <sys/dir.h>
#include <sys/stat.h>

#include <linux/lightbase/lightbase.h>
#include <linux/lightbase/symbol.h>

long long g_lb_base_addr;

void get_base_addr()
{
	long long addr = 0;
	char str_addr[13];

	str_addr[12] = 0;

	FILE *f = fopen("/proc/self/maps", "rb");
	fread(str_addr, 12, 1, f);
	fclose(f);
	sscanf(str_addr, "%llx", &g_lb_base_addr);

	printf("[LightBase] [INFO] Base addr: %p\n", g_lb_base_addr);
}

int load_symbols()
{
	FILE *f = fopen("bedrock_server_symbols.debug", "rb");
	if (!f) {
		printf("[LightBase] [ERROR] Failed to open bedrock_server_symbols.debug: %s.\n", strerror(errno));

		return -1;
	}

	return lb_load_symbols(f);
}

void load_plugins()
{
	int ret = 0;
	DIR *dir = opendir(PLUGIN_DIR);
	if (!dir) {
		if (errno == ENOENT) {
			printf("[LightBase] [INFO] No plugins folder found, creating...\n");
			ret = mkdir("plugins", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
			if (ret) {
				printf("[LightBase] [INFO] Create plugins folder failed: %s.\n", strerror(errno));
			}

			return;
		} else {
			printf("[LightBase] [ERROR] Open plugins folder failed: %s.\n", strerror(errno));

			return;
		}
	}

	struct dirent *dir_ctx;
	const char *f_name_suffix;
	size_t f_name_len;
	char plugin_path[512];

	while ((dir_ctx = readdir(dir))) {
		f_name_len = strlen(dir_ctx->d_name);
		sprintf(plugin_path, PLUGIN_DIR "%s", dir_ctx->d_name);
		if (f_name_len >= 3) {
			f_name_suffix = dir_ctx->d_name + f_name_len - 3;
			if (!strcmp(f_name_suffix, ".so")) {
				printf("[LightBase] [INFO] Loading %s.\n", dir_ctx->d_name);
				void *ret_ = dlopen(plugin_path, RTLD_NOW);
				if (!ret_) {
					printf("[LightBase] [ERROR] Load plugin %s failed: %s.\n", dir_ctx->d_name, dlerror());
				}
				printf("[LightBase] [INFO] Loaded %s.\n", dir_ctx->d_name);
			}
		} else {
			continue;
		}
	}
}

// init
void lb_init()
{
	int ret = 0;

	printf("[LightBase] -------------------------------------------------------------------------------------------------------------------------\n");
	printf("[LightBase] \n");
	printf("[LightBase] 88           88               88                   88888888ba                                      \n");
	printf("[LightBase] 88           \"\"               88            ,d     88      \"8b                                     \n");
	printf("[LightBase] 88                            88            88     88      ,8P                                     \n");
	printf("[LightBase] 88           88   ,adPPYb,d8  88,dPPYba,  MM88MMM  88aaaaaa8P'  ,adPPYYba,  ,adPPYba,   ,adPPYba,  \n");
	printf("[LightBase] 88           88  a8\"    `Y88  88P\'    \"8a   88     88\"\"\"\"\"\"8b,  \"\"     `Y8  I8[    \"\"  a8P_____88  \n");
	printf("[LightBase] 88           88  8b       88  88       88   88     88      `8b  ,adPPPPP88   `\"Y8ba,   8PP\"\"\"\"\"\"\"  \n");
	printf("[LightBase] 88           88  \"8a,   ,d88  88       88   88,    88      a8P  88,    ,88  aa    ]8I  \"8b,   ,aa  \n");
	printf("[LightBase] 88888888888  88   `\"YbbdP\"Y8  88       88   \"Y888  88888888P\"   `\"8bbdP\"Y8  `\"YbbdP\"'   `\"Ybbd8\"'  \n");
	printf("[LightBase]                   aa,    ,88                                                                       \n");
	printf("[LightBase]                    \"Y8bbdP\"                                                                        \n");
	printf("[LightBase] \n");
	printf("[LightBase] -------------------------------------------------------------------------------------------------------------------------\n");

	get_base_addr();
	ret = load_symbols();
	if (ret == -1) {
		return;
	}
	load_plugins();
}