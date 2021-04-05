/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map zoom
*/

#include "Rpg/rpg.h"
#include "functions.h"
#include "My/my_display.h"

static float verif_zoom(map_t *map, float zoom)
{
    float new_zoom = map->current_zoom * zoom;
    sfVector2f min_zooms = {\
        map->current_zone->battle.size.x * map->tiles_size, \
        map->current_zone->battle.size.y * map->tiles_size};
    float min_zoom;

    min_zooms.x /= map->view_size.x;
    min_zooms.y /= map->view_size.y;
    min_zoom = MIN(min_zooms.x, min_zooms.y);
    if (new_zoom > min_zoom)
        return min_zoom / map->current_zoom;
    if (new_zoom < 0.4f)
        return 0.4f / map->current_zoom;
    return zoom;
}

void map_zoom(map_t *map, float value)
{
    sfVector2f player_pos = {map->rpg->player->body->pos.x * M_TO_PX, \
        map->rpg->player->body->pos.y * M_TO_PX};
    sfVector2i player = sfRenderWindow_mapCoordsToPixel(map->rpg->wind, \
    player_pos, map->view);
    sfVector2f aft_coo;
    sfVector2f offset;
    float zoom;

    if (!map->current_zone->world)
        return;
    zoom = value;
    map->current_zoom *= zoom;
    sfView_zoom(map->view, zoom);
    aft_coo = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    player, map->view);
    offset = (sfVector2f){player_pos.x - aft_coo.x, player_pos.y - aft_coo.y};
    sfView_move(map->view, offset);
}

void map_update_zoom(map_t *map, float dt)
{
    float delta = fabsf(map->current_zoom - map->zoom_goal);

    if (map->zoom_goal == 0)
        return;
    if (delta < 0.001f) {
        map_zoom(map, map->zoom_goal / map->current_zoom);
        map->zoom_goal = 0;
        return;
    }
    map_zoom(map, 1 + (map->zoom_goal / map->current_zoom - 1) * \
    dt * MAX(2, powf(delta * 7, 2)));
}

void map_zoom_up_down(map_t *map, int zoom_up)
{
    map->zoom_goal = map->current_zoom * \
    verif_zoom(map, (zoom_up) ? 0.8f : 1.25f);
}

void map_reset_zoom(map_t *map)
{
    map->zoom_goal = map->current_zoom * verif_zoom(map, 10000);
}