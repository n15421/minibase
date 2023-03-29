#include <example/hooks.h>
#include <example/nbs/nbs.h>
#include <example/nbs/megalovania.h>

extern struct string string;
extern struct level *g_level;

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

// Constructor for Level		
TMHOOK(level_construct, struct level*,
    "??0Level@@QEAA@AEBV?$not_null@V?$NonOwnerPointer@VSoundPlayerInterface@@@Bedrock@@@gsl@@V?$unique_ptr@VLevelStorage@@U?$default_delete@VLevelStorage@@@std@@@std@@V?$unique_ptr@VLevelLooseFileStorage@@U?$default_delete@VLevelLooseFileStorage@@@std@@@4@AEAVIMinecraftEventing@@_NW4SubClientId@@AEAVScheduler@@V?$not_null@V?$NonOwnerPointer@VStructureManager@@@Bedrock@@@2@AEAVResourcePackManager@@AEBV?$not_null@V?$NonOwnerPointer@VIEntityRegistryOwner@@@Bedrock@@@2@V?$WeakRefT@UEntityRefTraits@@@@V?$unique_ptr@VBlockComponentFactory@@U?$default_delete@VBlockComponentFactory@@@std@@@4@V?$unique_ptr@VBlockDefinitionGroup@@U?$default_delete@VBlockDefinitionGroup@@@std@@@4@VItemRegistryRef@@V?$weak_ptr@VBlockTypeRegistry@@@4@4V?$optional@VDimensionDefinitionGroup@@@4@@Z",
	struct level* _this, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5, uintptr_t a6, uintptr_t a7, uintptr_t a8, uintptr_t a9, uintptr_t a10, uintptr_t a11, uintptr_t a12, uintptr_t a13, uintptr_t a14, uintptr_t a15, uintptr_t a16, uintptr_t a17)
{
	return g_level = level_construct.original(_this, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17);
}

/*
 * A two-dimensional array for storing players and their play sequences
 *
 * 0: player pointer
 * 1: Last played to position
 * 2: Next play to position
 */
unsigned long long g_note_queue[MAX_ONLINE_PLAYER][3];

DWORD WINAPI make_note_queue_thread(LPVOID lpParameter)
{
    struct player *player = (struct player *)lpParameter;
    const char *player_name = get_name_tag((struct actor *)player);
    char start_msg[128] = "Start playing music: ";
    char stop_msg[128] = "Stop playing music: ";
    int player_index = 0;
    LARGE_INTEGER start_time, end_time, elapsed_time, frequency;

    QueryPerformanceFrequency(&frequency);

    strcat(start_msg, player_name);
    strcat(stop_msg, player_name);

    while (player) {
        for (int i = 0; i < MAX_ONLINE_PLAYER; i++) {
            if (g_note_queue[i][0] == (uintptr_t)player) {
                player_index = i;
                break;
            }
        }

        server_logger(start_msg, INFO);
        for (int j = 0; j < MAX_NOTE_LEN; j++) {
            QueryPerformanceCounter(&start_time);
            elapsed_time.QuadPart = 0;

            while (elapsed_time.QuadPart < (LONGLONG)(NOTE_DATA[j][0] * frequency.QuadPart / 1000)) {
                QueryPerformanceCounter(&end_time);
                elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            }

            g_note_queue[player_index][2] = j;
        }
        server_logger(stop_msg, INFO);
    }
    memset(g_note_queue[player_index], 0, sizeof(g_note_queue[player_index]));
    return 0;
}

void send_music_sound_packet(void)
{
    struct player *player = NULL;
    struct vec3 *pos;
    unsigned long long note_index = 0;
    const char *sound_name;
    float volume;
    float pitch;

    for (int i = 0; i < MAX_ONLINE_PLAYER; i++) {
        if (g_note_queue[i][0] == 0)
            continue;

        player = (struct player *)(g_note_queue[i][0]);

        for (note_index = g_note_queue[i][1]; note_index < g_note_queue[i][2]; note_index++) {
            if (!player) {
                memset(g_note_queue[i], 0, sizeof(g_note_queue[i]));
                break;
            }
            pos = actor_get_pos((struct actor *)player);
            sound_name = BUILTIN_INSTRUMENT[(int)(NOTE_DATA[note_index][1])];
            volume = NOTE_DATA[note_index][2];
            pitch = NOTE_DATA[note_index][3];

            send_play_sound_packet(player, sound_name, *pos, volume, pitch);
        }
        g_note_queue[i][1] = g_note_queue[i][2];
    }
}

TMHOOK(on_player_join, void,
    "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVSetLocalPlayerAsInitializedPacket@@@Z",
	struct server_network_handler *_this, uintptr_t id,/*SetLocalPlayerAsInitializedPacket*/ uintptr_t pkt)
{
    struct player *player = get_server_player(_this, id, pkt);

    server_logger(get_name_tag((struct actor *)player), UNKNOWN);
    server_logger(get_player_xuid(player), UNKNOWN);

    for (int i = 0; i < MAX_ONLINE_PLAYER; i++) {
        if (g_note_queue[i][0] == 0) {
            g_note_queue[i][0] = (uintptr_t)player;
            break;
        }
    }
    HANDLE hThread = CreateThread(NULL, 0, make_note_queue_thread, player, 0, NULL);

	on_player_join.original(_this, id, pkt);
}

TMHOOK(on_tick, void,
	"?tick@Level@@UEAAXXZ",
	struct level *level)
{
    send_music_sound_packet();
    on_tick.original(level);
}

bool init_hooks(void)
{
    on_console_input.init(&on_console_input);
    on_server_started.init(&on_server_started);
    on_console_output.init(&on_console_output);
    on_liquid_spread.init(&on_liquid_spread);
    on_player_attack.init(&on_player_attack);
    level_construct.init(&level_construct);
    on_player_join.init(&on_player_join);
    on_tick.init(&on_tick);

    hooker_enable_all_hook();
    return true;
}
