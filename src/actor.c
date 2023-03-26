#include <example/actor.h>

struct vec3 *actor_get_pos(struct actor *actor)
{
	return TMCALL("?getPosition@Actor@@UEBAAEBVVec3@@XZ",
        struct vec3 *(*)(struct actor *actor),
        actor);
}
