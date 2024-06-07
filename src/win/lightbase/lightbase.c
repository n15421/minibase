#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <Windows.h>

#include <universal/lightbase/lightbase.h>
#include <win/minhook/MinHook.h>

bool enable_all_hook()
{
	if (MH_QueueEnableHook(MH_ALL_HOOKS) != MH_OK)
		return false;
	if (MH_ApplyQueued() != MH_OK)
		return false;

	return true;
}

bool disable_all_hook()
{
	if (MH_QueueDisableHook(MH_ALL_HOOKS) != MH_OK)
		return false;
	if (MH_ApplyQueued() != MH_OK)
		return false;

	return true;
}

int load_plugins()
{
	WIN32_FIND_DATA plugin_file;

start:

	HANDLE plugins = FindFirstFile(PLUGIN_DIR "*.dll", &plugin_file);
	if (plugins == INVALID_HANDLE_VALUE) {
		switch (GetLastError()) {
			case ERROR_FILE_NOT_FOUND:
				printf("No plugin\n");

				return -1;
				break;

			case ERROR_PATH_NOT_FOUND:

				printf("Create dir\n");
				if (!CreateDirectory("plugins", NULL)) {
					printf("Create dir fail\n");

					return -1;
				}

				goto start;
				break;

			default:
				break;
		}

		printf("Error: %d\n", GetLastError());

		return -1;
	}

	char plugin_name[256];

	do {
		printf("plugin: %s\n", plugin_file.cFileName);
		sprintf(plugin_name, PLUGIN_DIR "%s", plugin_file.cFileName);

		if (!LoadLibrary(plugin_name)) {
			printf("Plugin %s load failed: %d\n", plugin_name, GetLastError());
		}
	} while (FindNextFile(plugins, &plugin_file));

	return 0;
}

void lb_uninit()
{
	lb_sym_free();

	if (MH_Uninitialize() != MH_OK)
		return;

	return;
}

bool lb_init()
{
	char fail = 0;
	int ret = 0;

	if (MH_Initialize() != MH_OK)
		return false;

	ret = lb_load_symbols("bedrock_server.pdb");
	if (ret == -1) {
		lb_uninit();

		return false;
	}

	ret = load_plugins();
	if (ret == -1) {
		lb_uninit();

		return false;
	}

	enable_all_hook();

	// check_server_update();

	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule,
					  DWORD ul_reason_for_call,
					  LPVOID lpReserved)
{
	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
			DWORD mode;
			SetConsoleCP(CP_UTF8);
			SetConsoleOutputCP(CP_UTF8);
			GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
			SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

			lb_init();
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			lb_uninit();
			break;
	}
	return true;
}