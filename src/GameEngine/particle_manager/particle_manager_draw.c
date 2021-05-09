/*
** EPITECH PROJECT, 2021
** MyRPG - GameEngine
** File description:
** Draws the particles
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>

#include "GameEngine/particle_manager.h"

static void particle_manager_draw_at(particle_manager_t const *manager,
    sfRenderWindow *window, unsigned i, unsigned j)
{
    size_t pos = i * PARTICLES_PER_GROUP + j;
    sfSprite *sprite = manager->sprites[(size_t)manager->types[pos]];

    sfSprite_setPosition(sprite, manager->positions[pos]);
    sfSprite_setRotation(sprite, manager->rotations[pos]);
    sfSprite_setColor(sprite, manager->colors[pos]);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void particle_manager_draw(
    particle_manager_t const *manager, sfRenderWindow *window)
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
            particle_manager_draw_at(manager, window, i, j);
        group <<= 1;
        ++j;
    }
}
