/*
** EPITECH PROJECT, 2020
** Duck hunt
** File description:
** delete drawable
*/

#include "GameEngine/game_head.h"
#include "Drawables/drawables_head.h"

void destroy_drawable(draw_elmt_t *drawable)
{
    switch (drawable->dtype) {
    case D_RECT:
        sfRectangleShape_destroy(drawable->draw->rect);
        break;
    case D_TEXT:
        sfText_destroy(drawable->draw->text);
        break;
    }
    free(drawable->draw);
    free(drawable);
}

void destroy_draw_layer(my_map_t *layer)
{
    size_t nb_draw = my_map_size(layer);

    for (size_t i = 0; i < nb_draw; i++)
        destroy_drawable((draw_elmt_t *)my_map_at(layer, i));
    my_map_clear(layer);
}

void delete_drawables(my_map_t *layer, int tag)
{
    size_t pos;

    if (tag == 0){
        destroy_draw_layer(layer);
        return;
    }
    pos = my_map_find_index(layer, tag);
    destroy_drawable((draw_elmt_t *)my_map_at(layer, pos));
    my_map_erase_index(layer, pos);
}