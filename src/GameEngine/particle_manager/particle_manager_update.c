/*
** EPITECH PROJECT, 2021
** MyRPG - GameEngine
** File description:
** Updates the particle manager
*/

#include "GameEngine/particle_manager.h"

static void particle_manager_update_at(
    particle_manager_t *manager, float dt, unsigned i, unsigned j)
{
    size_t pos = i * PARTICLES_PER_GROUP + j;
    float rem_percent;

    manager->elapsed[pos] += dt;
    if (manager->elapsed[pos] >= manager->durations[pos]) {
        manager->active[i] &=
            ~(PARTICLE_GROUP_C(1) << (PARTICLES_PER_GROUP - j - 1));
        return;
    }
    rem_percent = 1 - (manager->elapsed[pos] / manager->durations[pos]);
    manager->colors[pos].a = 255 * rem_percent;
    manager->positions[pos].y -= manager->speeds[pos] * dt;
}

void particle_manager_update(particle_manager_t *manager, float dt)
{
    unsigned i = 0;
    unsigned j = 0;
    particle_group_t group = manager->active[0];
    int empty_count;

    while (i < MAX_PARTICLE_GROUPS) {
        if (group == PARTICLE_GROUP_EMPTY) {
            group = manager->active[++i];
            j = 0;
            continue;
        }
        empty_count = PARTICLE_COUNT_ZERO(group);
        group <<= empty_count;
        j += empty_count;
        if (group != PARTICLE_GROUP_EMPTY)
            particle_manager_update_at(manager, dt, i, j);
        group <<= 1;
        ++j;
    }
}
