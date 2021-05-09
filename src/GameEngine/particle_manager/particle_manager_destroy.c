/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Destroys the particle manager
*/

#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

#include "GameEngine/particle_manager.h"

void particle_manager_destroy(particle_manager_t *manager)
{
    manager->count = 0;
    for (size_t i = 0; i < PARTICLE_TYPE_COUNT; ++i)
        sfSprite_destroy(manager->sprites[i]);
    free(manager);
}
