/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map update
*/

#include "Rpg/rpg.h"
#include "My/my_display.h"

static sfVector2f coord_to_px_float(sfRenderWindow *wind, \
sfVector2f pos, map_t *map)
{
    float zoom = map->current_zoom;
    sfVector2f view_center = sfView_getCenter(map->view);
    sfVector2f view_tl = {view_center.x - (map->view_size.x * zoom) / 2, \
        view_center.y - (map->view_size.y * zoom) / 2};
    sfVector2f pos_flt = {pos.x - view_tl.x, pos.y - view_tl.y};

    pos_flt.x /= zoom;
    pos_flt.y /= zoom;
    return pos_flt;
}

void map_update(map_t *map, float dt)
{
    sfVector2f view_size = map->view_size;
    sfVector2f player_pos = map->rpg->player->pos;
    sfVector2f local_player_pos = coord_to_px_float(map->rpg->wind, \
    player_pos, map);
    sfVector2f offset = (sfVector2f){local_player_pos.x - view_size.x / \
        2.f, local_player_pos.y - view_size.y / 2.f};

    if (abs(offset.x) >= view_size.x / 10.f)
        offset.x = local_player_pos.x - \
        ((4 + 2 * (offset.x > 0)) * view_size.x) / 10.f;
    else
        offset.x = 0;
    if (abs(offset.y) >= view_size.y / 10.f)
        offset.y = local_player_pos.y - \
        ((4 + 2 * (offset.y > 0)) * view_size.y) / 10.f;
    else
        offset.y = 0;
    map_move(map, offset);
}