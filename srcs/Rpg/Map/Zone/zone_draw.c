/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone draw
*/

#include "Rpg/rpg.h"
#include "functions.h"

void zone_draw(zone_t *zone, sfRenderWindow *wind)
{
    sfVector2f view_pos = zone->map->view_pos;
    sfVector2f view_size = zone->map->view_size;
    sfView *view = zone->map->view;
    sfVector2f top_left = sfRenderWindow_mapPixelToCoords(wind, \
    (sfVector2i){view_pos.x, view_pos.y}, view);
    sfVector2f bottom_right = sfRenderWindow_mapPixelToCoords(wind, \
    (sfVector2i){view_pos.x + view_size.x, \
        view_pos.y + view_size.y}, view);
    sfVector2i min_pos = {MAX(top_left.x / zone->tiles_size, 0), \
        MAX(top_left.y / zone->tiles_size, 0)};
    sfVector2i max_pos = {MIN(bottom_right.x / zone->tiles_size + 1, \
        zone->size.x), MIN(bottom_right.y / \
        zone->tiles_size + 1, zone->size.y)};
    const sfView *base_view = sfRenderWindow_getDefaultView(wind);

    sfRenderWindow_setView(wind, view);
    for (int i = 0; i < zone->nb_layers; i++)
        layer_draw(zone->layers[i], wind, min_pos, max_pos);
    sfRenderWindow_setView(wind, base_view);
}