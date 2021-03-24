/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map update
*/

#include "Rpg/rpg.h"

void map_update(map_t *map, float dt)
{
    sfVector2f view_size = map->view_size;
    sfVector2f player_pos = map->rpg->player->pos;
    sfVector2i local_player_pos = sfRenderWindow_mapCoordsToPixel(\
    map->rpg->wind, player_pos, map->view);
    sfVector2f offset = (sfVector2f){local_player_pos.x - view_size.x / \
        2.f, local_player_pos.y - view_size.y / 2.f};

    if (abs(offset.x) > view_size.x / 10.f)
        offset.x = local_player_pos.x - \
        ((4 + 2 * (offset.x > 0)) * view_size.x) / 10.f;
    else
        offset.x = 0;
    if (abs(offset.y) > view_size.y / 10.f)
        offset.y = local_player_pos.y - \
        ((4 + 2 * (offset.y > 0)) * view_size.y) / 10.f;
    else
        offset.y = 0;
    map_move(map, offset);
    pe_world_update(map->current_zone->world, dt * 1000);
}