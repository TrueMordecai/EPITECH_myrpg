/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** layer create
*/

#include "Rpg/Map/layer.h"
#include "My/my_memory.h"

layer_t *layer_create(sfTexture *tex, int tiles_size)
{
    layer_t *layer = my_calloc(sizeof(layer_t), 0);

    layer->tex = tex;
    layer->tiles_size = tiles_size;
    return layer;
}