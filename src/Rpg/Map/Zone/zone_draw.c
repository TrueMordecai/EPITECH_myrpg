/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone draw
*/

#include "Rpg/rpg.h"
#include "functions.h"

static int is_player_btwn(zone_t *zone, float y_player, int i)
{
    int y1 = zone->layers[i]->pos.y + zone->layers[i]->size.y;
    int y2;

    if (i > 0)
        y2 = zone->layers[i - 1]->pos.y + zone->layers[i - 1]->size.y;
    else
        y2 = 0;
    return (y1 >= y_player && y_player >= y2);
}

static void get_min_max(
    zone_t *zone, sfRenderWindow *wind, sfVector2i *min, sfVector2i *max)
{
    sfVector2f view_pos = zone->map->view_pos;
    sfVector2f view_size = zone->map->view_size;
    sfView *view = zone->map->view;
    sfVector2f top_left = sfRenderWindow_mapPixelToCoords(
        wind, (sfVector2i){view_pos.x, view_pos.y}, view);
    sfVector2f bottom_right = sfRenderWindow_mapPixelToCoords(wind,
        (sfVector2i){view_pos.x + view_size.x, view_pos.y + view_size.y},
        view);
    sfVector2i min_pos = {MAX(top_left.x / zone->tiles_size, 0),
        MAX(top_left.y / zone->tiles_size, 0)};
    sfVector2i max_pos = {
        MIN(bottom_right.x / zone->tiles_size + 1, zone->size.x),
        MIN(bottom_right.y / zone->tiles_size + 1, zone->size.y)};

    *min = (sfVector2i){min_pos.x, min_pos.y};
    *max = (sfVector2i){max_pos.x, max_pos.y};
}

void zone_draw_layers(
    zone_t *zone, sfRenderWindow *wind, sfVector2i min, sfVector2i max)
{
    player_t *player = zone->map->rpg->player;
    int i = 0;
    float y_player =
        (player->pos.y
            + sfRectangleShape_getSize(player->entity->rect).y * 1.2)
        / (float)zone->tiles_size;

    sfRenderWindow_setView(wind, zone->map->view);
    do {
        layer_draw(zone->layers[i], wind, min, max);
        i++;
    } while (i < zone->nb_layers && !is_player_btwn(zone, y_player, i));
    player_draw(player, wind);
    for (int layer = i; layer < zone->nb_layers; layer++)
        layer_draw(zone->layers[layer], wind, min, max);
}

void zone_draw(zone_t *zone, sfRenderWindow *wind)
{
    sfVector2i min;
    sfVector2i max;

    get_min_max(zone, wind, &min, &max);
    if (!zone->world)
        return;
    if (zone->is_battle)
        battle_draw(&zone->battle, wind, min, max);
    else
        zone_draw_layers(zone, wind, min, max);
}
