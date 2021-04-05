/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Drawables lists fcts
*/

#include "GameEngine/game_head.h"
#include "Drawables/drawables_head.h"

static void draw_element(draw_elmt_t *elmt, sfRenderTexture *texture)
{
    if ((elmt->dtype & 128) != 0)
        return;
    switch (elmt->dtype) {
    case D_RECT:
        sfRenderTexture_drawRectangleShape(texture, elmt->draw->rect, NULL);
        break;
    case D_TEXT:
        sfRenderTexture_drawText(texture, elmt->draw->text, NULL);
        break;
    }
}

void draw_map_texture(my_map_t *map, sfRenderTexture *texture)
{
    for (size_t i = 0; i < my_map_size(map); i++){
        draw_element((draw_elmt_t *)my_map_at(map, i), texture);
    }
}

void draw_vec_texture(draw_elmt_t **vec, sfRenderTexture *texture)
{
    for (size_t i = 0; i < my_vector_get_size((size_t *)vec); i++){
        draw_element(vec[i], texture);
    }
}