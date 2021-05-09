/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Clears the current particles
*/

#include "GameEngine/particle_manager.h"

void particle_manager_clear(particle_manager_t *manager)
{
    manager->count = 0;
    for (size_t i = 0; i < MAX_PARTICLE_GROUPS; ++i)
        manager->active[i] = PARTICLE_GROUP_EMPTY;
}
