/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** layer place tile
*/

#include "Rpg/Map/layer.h"
#include "My/my_display.h"
static void init_rect(layer_t *layer, int pos_id, sfVector2f pos, int tile)
{
    sfRectangleShape *rect = layer->tiles[pos_id];

    if (!rect)
        rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setTexture(rect, layer->tex, 1);
    sfRectangleShape_setTextureRect(rect, (sfIntRect)\
    {(tile % SET_WIDTH) * TILE_SIZE, \
        (tile / SET_WIDTH) * TILE_SIZE, \
        TILE_SIZE, TILE_SIZE});
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, -1);
    sfRectangleShape_setSize(rect, \
    (sfVector2f){layer->tiles_size, layer->tiles_size});
    layer->tiles[pos_id] = rect;
}

void layer_place_tile(layer_t *layer, sfVector2i pos, int tile)
{
    if (pos.x < layer->pos.x || pos.y < layer->pos.y || \
        pos.x >= layer->pos.x + layer->size.x || \
        pos.y >= layer->pos.y + layer->size.y)
        return;
    init_rect(layer, pos.x - layer->pos.x + \
    (pos.y - layer->pos.y) * layer->size.x, \
    (sfVector2f){pos.x * layer->tiles_size, pos.y * layer->tiles_size}, tile);
}