/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map move
*/

#include "Rpg/rpg.h"
#include "My/my_display.h"

void map_correct_pos(map_t *map)
{
    sfVector2f top_left = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    (sfVector2i){map->view_pos.x, map->view_pos.y}, map->view);
    sfVector2f br = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    (sfVector2i){map->view_pos.x + map->view_size.x, \
        map->view_pos.y + map->view_size.y}, map->view);
    sfVector2f offset = {((top_left.x < 0) ? -top_left.x : 0), \
        ((top_left.y < 0) ? -top_left.y : 0)};

    if (!map->current_zone->world)
        return;
    if (offset.x == 0 && top_left.x != 0 && \
        br.x > ((map->current_zone->size.x) * map->tiles_size))
        offset.x = ((map->current_zone->size.x) * map->tiles_size) - br.x;
    if (offset.y == 0 && top_left.y != 0 && \
        br.y > ((map->current_zone->size.y) * map->tiles_size))
        offset.y = ((map->current_zone->size.y) * map->tiles_size) - br.y;
    sfView_move(map->view, offset);
}

void map_move(map_t *map, sfVector2f offset)
{
    sfView_move(map->view, offset);
    map_correct_pos(map);
}