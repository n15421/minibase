#include <win/lightbase/loader.h>

static void print_err_msg()
{
	int err_msg_id = (int)GetLastError();
	if (err_msg_id == 0) {
		puts("unknown err");
		return;
	}
	LPWSTR msg_buffer = NULL;
	FormatMessageW(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM, NULL, err_msg_id,
			MAKELANGID(0x09, SUBLANG_DEFAULT), (LPWSTR)&msg_buffer, 0, NULL);
	wprintf(L"%d: %s\n", err_msg_id, msg_buffer);
	LocalFree(msg_buffer);
}

void load_plugins()
{
	puts("LightBase Loaded!");
	int count;
	char **filenames = get_filenames(PLUGIN_PATH, &count);
	for (int i = 0; i < count; i++) {
		if (strstr(filenames[i], ".dll")) {
			int path_len = strlen(PLUGIN_PATH) + strlen(filenames[i]) + 2;
			char *plugin_path = (char *)malloc(path_len);
			sprintf(plugin_path, "%s/%s", PLUGIN_PATH, filenames[i]);
			printf("Loading %s...\n", filenames[i]);
			HMODULE module = LoadLibrary(plugin_path);
			free(plugin_path);
			if (!module) {
				printf("Error when loading %s: %d!\n", filenames[i], GetLastError());
				continue;
			}
		}
	}
	free_filenames(filenames, count);
}

void wait_for_debugger()
{
	while (!IsDebuggerPresent()) {
		Sleep(200);
	}
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
			load_plugins();
			lb_enable_all_hook();
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
