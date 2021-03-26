/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map move
*/

#include "Rpg/rpg.h"
#include "My/my_display.h"

static sfVector2f get_offset(zone_t *zone, sfVector2f top_left, sfVector2f br)
{
    int ts = M_TO_PX;
    sfVector2i size_battle = {zone->battle.size.x * ts, \
        zone->battle.size.y * ts};
    sfVector2i pos_battle = {zone->battle.pos.x * ts, zone->battle.pos.y * ts};
    sfVector2f offset = (sfVector2f){\
        (top_left.x < pos_battle.x) ? (-top_left.x + pos_battle.x): 0, \
        (top_left.y < pos_battle.y) ? (-top_left.y + pos_battle.y) : 0};

    if (offset.x == 0 && top_left.x != pos_battle.x && \
        br.x > pos_battle.x + size_battle.x)
        offset.x = (pos_battle.x + size_battle.x) - br.x;
    if (offset.y == 0 && top_left.y != pos_battle.y && \
        br.y > pos_battle.y + size_battle.y)
        offset.y = (pos_battle.y + size_battle.y) - br.y;
    return offset;
}

void map_correct_pos(map_t *map)
{
    sfVector2f top_left = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    (sfVector2i){map->view_pos.x, map->view_pos.y}, map->view);
    sfVector2f br = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    (sfVector2i){map->view_pos.x + map->view_size.x, \
        map->view_pos.y + map->view_size.y}, map->view);

    if (!map->current_zone->world)
        return;
    sfView_move(map->view, get_offset(map->current_zone, top_left, br));
}

void map_move(map_t *map, sfVector2f offset)
{
    sfView_move(map->view, offset);
    map_correct_pos(map);
}