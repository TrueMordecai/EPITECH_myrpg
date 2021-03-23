/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** layer init
*/

#include "Rpg/Map/layer.h"
#include "My/my_memory.h"

void layer_init(layer_t *layer, sfVector2i size, int y, sfVector2i pos)
{
    layer->y = y;
    layer->pos = pos;
    layer->size = size;
    layer->tiles = my_calloc(sizeof(sfRectangleShape *) * size.x * size.y, 0);
}