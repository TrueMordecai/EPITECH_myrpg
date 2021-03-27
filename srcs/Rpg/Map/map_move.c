/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map move
*/

#include "Rpg/rpg.h"
#include "My/my_display.h"

static sfVector2i get_size(battle_t *battle, sfVector2f top_left, sfVector2f br)
{
    sfVector2i size_win = {(br.x - top_left.x), (br.y - top_left.y)};
    sfVector2i size = {MAX(battle->size.x * M_TO_PX, size_win.x), \
        MAX(battle->size.y * M_TO_PX, size_win.y)};

    return size;
}

static sfVector2i get_pos(battle_t *battle, sfVector2i size)
{
    sfVector2i size_diff = {size.x - battle->size.x * M_TO_PX, \
        size.y - battle->size.y * M_TO_PX};
    sfVector2i pos = {CLAMP(battle->pos.x * M_TO_PX - size_diff.x / 2.f, 0, \
        battle->zone->size.x * M_TO_PX - size.x), \
        CLAMP(battle->pos.y * M_TO_PX - size_diff.y / 2.f, 0, \
        battle->zone->size.y * M_TO_PX - size.y)};

    return pos;
}

static sfVector2f get_offset(zone_t *zone, sfVector2f top_left, \
sfVector2f br, float dt)
{
    sfVector2i size_battle = get_size(&zone->battle, top_left, br);
    sfVector2i pos_battle = get_pos(&zone->battle, size_battle);
    sfVector2f diffs_tl = {\
        (top_left.x < pos_battle.x) ? (-top_left.x + pos_battle.x) : 0, \
        (top_left.y < pos_battle.y) ? (-top_left.y + pos_battle.y) : 0};
    sfVector2f diffs_br = {\
        (br.x > pos_battle.x + size_battle.x) ? \
    (pos_battle.x + size_battle.x) - br.x : 0, \
        (br.y > pos_battle.y + size_battle.y) ? \
    (pos_battle.y + size_battle.y) - br.y : 0};
    sfVector2f offset = {0, 0};

    offset.x = (fabsf(diffs_tl.x) > fabsf(diffs_br.x)) ? \
diffs_tl.x : diffs_br.x;
    offset.y = (fabsf(diffs_tl.y) > fabsf(diffs_br.y)) ? \
diffs_tl.y : diffs_br.y;
    return (sfVector2f){MIN(offset.x, powf(offset.x, 2) * dt), \
        MIN(offset.y, powf(offset.y, 2) * dt)};
}

void map_correct_pos(map_t *map, float dt)
{
    sfVector2f top_left = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    (sfVector2i){map->view_pos.x, map->view_pos.y}, map->view);
    sfVector2f br = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    (sfVector2i){map->view_pos.x + map->view_size.x, \
        map->view_pos.y + map->view_size.y}, map->view);

    if (!map->current_zone->world)
        return;
    sfView_move(map->view, get_offset(map->current_zone, top_left, br, dt));
}

void map_move(map_t *map, sfVector2f offset)
{
    sfView_move(map->view, offset);
}