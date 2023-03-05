#include <hooker/hooks.h>

const enum log_level
{
    INFO = 2u,
    WARN = 4u,
    UNKNOWN = 6u,
    ERR = 8u
};

bool server_started = false;
TMHOOK(on_server_started, void,
        "?startServerThread@ServerInstance@@QEAAXXZ",
        uintptr_t _this)
{
    server_started = true;
    
    TMCALL("?log@BedrockLog@@YAXW4LogCategory@1@V?$bitset@$02@std@@W4LogRule@1@W4LogAreaID@@IPEBDH4ZZ",
        char (*)(unsigned int a1, char a2, int a3, int a4, unsigned int a5, const char *a6, int a7, const char *a8),
        0, 1, 0, 12, UNKNOWN, "HOOKER->LOG", 114514, "injected!");

    TMCALL("?log@BedrockLog@@YAXW4LogCategory@1@V?$bitset@$02@std@@W4LogRule@1@W4LogAreaID@@IPEBDH4ZZ",
        char (*)(unsigned int a1, char a2, int a3, int a4, unsigned int a5, const char *a6, int a7, const char *a8),
        0, 1, 0, 12, WARN, "HOOKER->LOG", 1919810, "feel free!");

    on_server_started.original(_this);
}

TMHOOK(on_console_output, bool, 
        "??$_Insert_string@DU?$char_traits@D@std@@_K@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@QEBD_K@Z",
        uintptr_t _this, const char *str, size_t size)
{
    if (server_started)
        printf("detour_on_console_output: %s\n", str);
    
    return on_console_output.original(_this, str, size);
}

TMHOOK(on_console_input, bool,
        "??$inner_enqueue@$0A@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@AEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
        uintptr_t _this, const char *str)
{
    puts("detour_on_console_input: ");
    puts(str);
    // Disable the hook after the first call.
    on_console_input.disable(&on_console_input);
    return on_console_input.original(_this, str);
}


bool init_hooks(void)
{
    on_console_input.init(&on_console_input);
    on_server_started.init(&on_server_started);
    on_console_output.init(&on_console_output);

    return true;
}
