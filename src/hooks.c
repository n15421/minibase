#include <example/hooks.h>

extern struct string string;

bool server_started = false;
TMHOOK(on_server_started, void,
        "?startServerThread@ServerInstance@@QEAAXXZ",
        uintptr_t _this)
{
    server_started = true;

    int protocol_version = get_network_protocol_version();
    char protocol_version_str[16];
    _itoa(protocol_version, protocol_version_str, 10);

    struct string *cpp_str = string.string("injected!");
    const char *c_str = string.c_str(cpp_str);

    server_logger(c_str, UNKNOWN);
    server_logger("feel free!", WARN);
    server_logger("protocol version:", INFO);
    server_logger(protocol_version_str, ERR);

    free(cpp_str);
    on_server_started.original(_this);
}

TMHOOK(on_console_output, bool, 
        "??$_Insert_string@DU?$char_traits@D@std@@_K@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@QEBD_K@Z",
        uintptr_t _this, const char *str, size_t size)
{
    if (server_started) {
        server_logger("detour_on_console_output: ", ERR);
        server_logger(str, ERR);
        server_logger("\n", INFO);
        on_console_output.disable(&on_console_output);
    }
    
    return on_console_output.original(_this, str, size);
}

TMHOOK(on_console_input, bool,
        "??$inner_enqueue@$0A@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@AEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
        uintptr_t _this, const char *str)
{
    server_logger("detour_on_console_input: ", WARN);
    server_logger(str, WARN);
    server_logger("\n", INFO);
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

    struct string *block_name_string = REFERENCE(struct string, block_legacy, 128);

    const char *block_name = string.c_str(block_name_string);

    // Stopping the flow of lava
    if (strcmp(block_name, "minecraft:lava") == 0)
        return false;

    return on_liquid_spread.original(_this, a2, dst_pos, src_pos, a5);
}

TMHOOK(on_player_attack, bool,
    "?attack@Player@@UEAA_NAEAVActor@@AEBW4ActorDamageCause@@@Z",
	struct player *player, struct actor *actor, struct ActorDamageCause *cause)
{
    struct vec3 *pos = actor_get_pos((struct actor *)player);

    send_play_sound_packet(player, "ambient.weather.thunder", *pos, 1, 1);

	float attack_damage = calc_attack_damage((struct actor *)player, actor);
    const char *player_name = get_name_tag((struct actor *)player);

    char message[128];

    snprintf(message, sizeof(message),
            "\nAttacker: %s\nPosition: %.3lf, %.3lf, %.3lf\nDamage:   %.3lf", 
            player_name, pos->x, pos->y, pos->z, attack_damage);

    server_logger(message, WARN);

    return on_player_attack.original(player, actor, cause);
}

bool init_hooks(void)
{
    on_console_input.init(&on_console_input);
    on_server_started.init(&on_server_started);
    on_console_output.init(&on_console_output);
    on_liquid_spread.init(&on_liquid_spread);
    on_player_attack.init(&on_player_attack);

    hooker_enable_all_hook();
    return true;
}
