#include <example/hooks.h>

bool server_started = false;
TMHOOK(on_server_started, void,
        "?startServerThread@ServerInstance@@QEAAXXZ",
        uintptr_t _this)
{
    server_started = true;

    int protocol_version = get_network_protocol_version();
    char protocol_version_str[16];
    _itoa(protocol_version, protocol_version_str, 10);

    server_logger("injected!", UNKNOWN);
    server_logger("feel free!", WARN);
    server_logger("protocol version:", INFO);
    server_logger(protocol_version_str, ERR);

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

TMHOOK(on_liquid_spread, bool, 
	"?_canSpreadTo@LiquidBlockDynamic@@AEBA_NAEAVBlockSource@@AEBVBlockPos@@1E@Z",
	uintptr_t _this, struct block_source *a2, struct block_pos *dst_pos, struct block_pos *src_pos, char a5)
{
    struct _block *block =
        TMCALL("?getBlock@BlockSource@@UEBAAEBVBlock@@AEBVBlockPos@@@Z",
            struct _block* (*)(struct block_source *, struct block_pos *),
            a2, src_pos);

    struct _block_legacy *block_legacy = DEREFERENCE(struct _block_legacy *, block, 16);

    struct string *block_name_string = (struct string *)PTR_OFFSET(block_legacy, 128);

    const char *block_name = cpp_string__c_str(block_name_string);

    // Stopping the flow of lava
    if (strcmp(block_name, "minecraft:lava") == 0)
        return false;

    return on_liquid_spread.original(_this, a2, dst_pos, src_pos, a5);
}


bool init_hooks(void)
{
    on_console_input.init(&on_console_input);
    on_server_started.init(&on_server_started);
    on_console_output.init(&on_console_output);
    on_liquid_spread.init(&on_liquid_spread);

    hooker_enable_all_hook();
    return true;
}
