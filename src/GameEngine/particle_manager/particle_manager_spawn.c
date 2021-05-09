/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Spawns particles
*/

#include "GameEngine/particle_manager.h"

static size_t particle_manager_find_free(particle_manager_t *manager)
{
    for (unsigned i = 0; i < MAX_PARTICLE_GROUPS; ++i) {
        particle_group_t group = manager->active[i];
        int active_count;

        if (group == PARTICLE_GROUP_FULL)
            continue;
        active_count = PARTICLE_COUNT_ZERO(~group);
        manager->active[i] |=
            (PARTICLE_GROUP_C(1) << (PARTICLES_PER_GROUP - active_count - 1));
        return i * PARTICLES_PER_GROUP + (unsigned)active_count;
    }
    return SIZE_MAX;
}

void particle_manager_spawn(particle_manager_t *manager, particle_t particle)
{
    size_t id = particle_manager_find_free(manager);

    if (id == SIZE_MAX)
        return;
    manager->types[id] = particle.type;
    manager->positions[id] = particle.position;
    manager->colors[id] = particle.color;
    manager->rotations[id] = particle.rotation;
    manager->speeds[id] = particle.speed;
    manager->elapsed[id] = 0;
    manager->durations[id] = particle.duration;
    ++manager->count;
}
