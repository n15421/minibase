#pragma once
#include <hooker/hook.h>
#include "cpp_string.h"
#include "actor.h"

#define MAX_ONLINE_PLAYER 10

struct level;

struct player *get_player_by_xuid(struct level *level, const char *xuid);
