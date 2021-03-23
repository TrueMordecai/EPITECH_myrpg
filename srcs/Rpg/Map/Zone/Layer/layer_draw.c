/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** layer draw
*/

#include "Rpg/Map/layer.h"
#include "My/my_display.h"

static void draw_pos(layer_t *layer, int x, int y, sfRenderWindow *wind)
{
    sfRectangleShape *rect = layer->tiles[x + y * layer->size.x];

    if (!rect)
        return;
    sfRenderWindow_drawRectangleShape(wind, rect, NULL);
}

void layer_draw(layer_t *layer, sfRenderWindow *wind)
{
    for (int x = 0; x < layer->size.x; x++)
        for (int y = 0; y < layer->size.y; y++)
            draw_pos(layer, x, y, wind);
}