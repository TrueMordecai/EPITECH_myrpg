/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** layer draw
*/

#include "Rpg/Map/layer.h"
#include "functions.h"

static void draw_pos(layer_t *layer, int x, int y, sfRenderWindow *wind)
{
    sfRectangleShape *rect = layer->tiles[x + y * layer->size.x];

    if (!rect)
        return;
    sfRenderWindow_drawRectangleShape(wind, rect, NULL);
}

void layer_draw(
    layer_t *layer, sfRenderWindow *wind, sfVector2i min, sfVector2i max)
{
    min.x = MAX(0, min.x - layer->pos.x);
    min.y = MAX(0, min.y - layer->pos.y);
    max.x = MIN(layer->size.x, max.x - layer->pos.x);
    max.y = MIN(layer->size.y, max.y - layer->pos.y);
    for (int x = min.x; x < max.x; x++)
        for (int y = min.y; y < max.y; y++)
            draw_pos(layer, x, y, wind);
}
