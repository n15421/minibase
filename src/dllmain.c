#include <example/hooks.h>

bool load_plugin(void);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        if (MH_Initialize() != MH_OK) 
            return false;
        load_plugin();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        MH_Uninitialize();
        break;
    }
    return true;
}

bool load_plugin(void)
{
    init_hooks();

    return true;
}
