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
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(map->rpg->wind);
    sfVector2f bef_coo = \
    sfRenderWindow_mapPixelToCoords(map->rpg->wind, mouse_pos, map->view);
    sfVector2f aft_coo;
    sfVector2f offset;
    float zoom;

    if (!map->current_zone->world)
        return;
    zoom = verif_zoom(map, value);
    map->current_zoom *= zoom;
    sfView_zoom(map->view, zoom);
    aft_coo = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    mouse_pos, map->view);
    offset = (sfVector2f){bef_coo.x - aft_coo.x, bef_coo.y - aft_coo.y};
    sfView_move(map->view, offset);
}

void map_zoom_up_down(map_t *map, int zoom_up)
{
    map_zoom(map, (zoom_up) ? 0.8f : 1.25f);
}

void map_reset_zoom(map_t *map)
{
    map_zoom(map, 10000);
}