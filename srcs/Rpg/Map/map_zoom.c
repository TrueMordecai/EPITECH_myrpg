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
    sfVector2f min_zooms = {map->current_zone->size.x * map->tiles_size, \
        map->current_zone->size.y * map->tiles_size};
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

void map_zoom(map_t *map, int zoom_up)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(map->rpg->wind);
    sfVector2f bef_coo = \
    sfRenderWindow_mapPixelToCoords(map->rpg->wind, mouse_pos, map->view);
    sfVector2f aft_coo;
    sfVector2f offset;
    float zoom = verif_zoom(map, (zoom_up) ? 0.8 : 1.25);

    map->current_zoom *= zoom;
    sfView_zoom(map->view, zoom);
    aft_coo = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    mouse_pos, map->view);
    offset = (sfVector2f){bef_coo.x - aft_coo.x, bef_coo.y - aft_coo.y};
    sfView_move(map->view, offset);
}