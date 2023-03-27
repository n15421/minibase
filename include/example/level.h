#pragma once
#include <hooker/hook.h>
#include "cpp_string.h"
#include "actor.h"

struct level;

struct player *get_player_by_xuid(struct level *level, const char *xuid);
