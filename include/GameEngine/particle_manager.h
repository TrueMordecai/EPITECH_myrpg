/*
** EPITECH PROJECT, 2021
** MyRPG - GameEngine
** File description:
** The particle manager
*/

#ifndef __GE_PARTICLE_MANAGER_H__
#define __GE_PARTICLE_MANAGER_H__

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdint.h>

#include "types.h"

typedef unsigned long long particle_group_t;
#define PARTICLE_GROUP_C(l)    (l##ULL)
#define PARTICLE_GROUP_FULL    (~PARTICLE_GROUP_C(0))
#define PARTICLE_GROUP_EMPTY   (PARTICLE_GROUP_C(0))
#define PARTICLE_COUNT_ZERO(x) (__builtin_clzll((x)))

#define MAX_PARTICLE_GROUPS (8)
#define PARTICLES_PER_GROUP (sizeof(particle_group_t) * 8)
#define MAX_PARTICLE_COUNT  (MAX_PARTICLE_GROUPS * PARTICLES_PER_GROUP)

typedef enum particle_type {
    PARTICLE_BOOST,
    PARTICLE_TYPE_COUNT,
} particle_type_t;

struct particle_manager {
    size_t count;
    sfSprite *sprites[PARTICLE_TYPE_COUNT];
    particle_group_t active[MAX_PARTICLE_GROUPS];
    char types[MAX_PARTICLE_COUNT];
    sfVector2f positions[MAX_PARTICLE_COUNT];
    sfColor colors[MAX_PARTICLE_COUNT];
    float rotations[MAX_PARTICLE_COUNT];
    float speeds[MAX_PARTICLE_COUNT];
    float elapsed[MAX_PARTICLE_COUNT];
    float durations[MAX_PARTICLE_COUNT];
};

typedef struct particle {
    particle_type_t type;
    sfVector2f position;
    sfColor color;
    float rotation;
    float duration;
    float speed;
} particle_t;

particle_manager_t *particle_manager_create(asset_manager_t *asset_manager);
void particle_manager_destroy(particle_manager_t *manager);

void particle_manager_spawn(particle_manager_t *manager, particle_t particle);

void particle_manager_update(particle_manager_t *manager, float dt);

void particle_manager_draw(
    particle_manager_t const *manager, sfRenderWindow *window);

void particle_manager_clear(particle_manager_t *manager);

#endif // !defined(__GE_PARTICLE_MANAGER_H__)
