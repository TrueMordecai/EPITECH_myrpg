/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** layer init
*/

#include <libmy/memory/alloc.h>

#include "Rpg/Map/layer.h"

void layer_init(layer_t *layer, sfVector2i size, sfVector2i pos)
{
    layer->pos = pos;
    layer->size = size;
    layer->tiles = my_calloc(size.x * size.y, sizeof(sfRectangleShape *));
}
