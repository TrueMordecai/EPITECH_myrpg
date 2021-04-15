/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map update
*/

#include "Rpg/rpg.h"
#include "Rpg/Fight/fight.h"

static sfVector2f coord_to_px_float(sfVector2f pos, map_t *map)
{
    float zoom = map->current_zoom;
    sfVector2f view_center = sfView_getCenter(map->view);
    sfVector2f view_tl = {view_center.x - (map->view_size.x * zoom) / 2,
        view_center.y - (map->view_size.y * zoom) / 2};
    sfVector2f pos_flt = {pos.x - view_tl.x, pos.y - view_tl.y};

    pos_flt.x /= zoom;
    pos_flt.y /= zoom;
    return pos_flt;
}

static sfVector2f assert_offset(
    map_t *map, sfVector2f *offset, sfVector2f view_size)
{
    sfVector2f top_left = sfRenderWindow_mapPixelToCoords(map->rpg->wind,
        (sfVector2i){map->view_pos.x, map->view_pos.y}, map->view);
    sfVector2f br = sfRenderWindow_mapPixelToCoords(map->rpg->wind,
        (sfVector2i){map->view_pos.x + map->view_size.x,
            map->view_pos.y + map->view_size.y},
        map->view);
    sfVector2f factors = {powf(1.5f + 4 * fabsf(offset->x) / view_size.x, 2),
        powf(1.5f + 4 * fabsf(offset->y) / view_size.y, 2)};

    if (offset->x + top_left.x < 0 && offset->x < 0)
        offset->x = MIN(0, -top_left.x);
    else if (offset->x + br.x > map->current_zone->size.x * M_TO_PX
        && offset->x > 0)
        offset->x = MAX(0, map->current_zone->size.x * M_TO_PX - br.x);
    if (offset->y + top_left.y < 0 && offset->y < 0)
        offset->y = MIN(0, -top_left.y);
    else if (offset->y + br.y > map->current_zone->size.y * M_TO_PX
        && offset->y > 0)
        offset->y = MAX(0, map->current_zone->size.y * M_TO_PX - br.y);
    return factors;
}

void move_view_to_player(map_t *map, float dt)
{
    sfVector2f view_size = map->view_size;
    sfVector2f player_pos = map->rpg->player->pos;
    sfVector2f local_player_pos = coord_to_px_float(player_pos, map);
    sfVector2f offset = (sfVector2f){local_player_pos.x - view_size.x / 2.f,
        local_player_pos.y - view_size.y / 2.f};
    sfVector2f factors;

    if (fabs(offset.x) >= view_size.x / 10.f)
        offset.x = local_player_pos.x
            - ((4 + 2 * (offset.x > 0)) * view_size.x) / 10.f;
    else
        offset.x = 0;
    if (fabs(offset.y) >= view_size.y / 10.f)
        offset.y = local_player_pos.y
            - ((4 + 2 * (offset.y > 0)) * view_size.y) / 10.f;
    else
        offset.y = 0;
    factors = assert_offset(map, &offset, view_size);
    map_move(map,
        (sfVector2f){offset.x * MIN(1, dt * factors.x),
            offset.y * MIN(1, dt * factors.y)});
}

void map_update(map_t *map, float dt)
{
    if (!map->current_zone->is_battle)
        move_view_to_player(map, dt);
    map_correct_pos(map, dt);
    map_update_zoom(map, dt);
    if (map->current_zone->world) {
        if (!map->current_zone->is_battle)
            pe_world_update(map->current_zone->world, dt * 1000);
        else
            fight_update(map->current_zone->battle.fight, dt);
    }
}