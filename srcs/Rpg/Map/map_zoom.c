/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map zoom
*/

#include "Rpg/rpg.h"
#include "functions.h"

static int verif_zoom(map_t *map, float zoom)
{
    float new_size = map->tiles_size / (map->current_zoom * zoom);

    if (new_size <= 10 || new_size > \
        (MIN(map->view_size.x, map->view_size.y) / 2.f))
        return 0;
    return 1;
}

void map_zoom(map_t *map, int zoom_up)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(map->rpg->wind);
    sfVector2f bef_coo = \
    sfRenderWindow_mapPixelToCoords(map->rpg->wind, mouse_pos, map->view);
    sfVector2f aft_coo;
    sfVector2f offset;
    float zoom = (zoom_up) ? 0.8 : 1.25;

    if (!verif_zoom(map, zoom))
        return;
    map->current_zoom *= zoom;
    sfView_zoom(map->view, zoom);
    aft_coo = sfRenderWindow_mapPixelToCoords(map->rpg->wind, \
    mouse_pos, map->view);
    offset = (sfVector2f){bef_coo.x - aft_coo.x, bef_coo.y - aft_coo.y};
    sfView_move(map->view, offset);
}