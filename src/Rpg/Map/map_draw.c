/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map draw
*/

#include "Rpg/rpg.h"
#include "GameEngine/particle_manager.h"

void map_draw(map_t *map)
{
    const sfView *base_view = sfRenderWindow_getDefaultView(map->rpg->wind);

    zone_draw(map->current_zone, map->rpg->wind);
    particle_manager_draw(
        map->rpg->state->game_data->particles, map->rpg->wind);
    sfRenderWindow_setView(map->rpg->wind, base_view);
}
