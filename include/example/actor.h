#include <hooker/hook.h>
#include "position.h"
#include "cpp_string.h"

struct actor;
struct player;

struct vec3 *actor_get_pos(struct actor *actor);
float calc_attack_damage(struct actor *attacker, struct actor *casualty);
const char *get_name_tag(struct actor *actor);
