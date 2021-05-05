/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** layer destroy
*/

#include <stdlib.h>
#include "Rpg/Map/layer.h"

static void free_pos(layer_t *layer, int x, int y)
{
    if (layer->tiles[x + y * layer->size.x])
        sfRectangleShape_destroy(layer->tiles[x + y * layer->size.x]);
}

void layer_destroy(layer_t *layer)
{
    if (!layer->tiles) {
        free(layer);
        return;
    }
    for (int x = 0; x < layer->size.x; x++)
        for (int y = 0; y < layer->size.y; y++)
            free_pos(layer, x, y);
    free(layer->tiles);
    free(layer);
}
