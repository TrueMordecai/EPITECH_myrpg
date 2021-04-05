/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Drawables lists fcts
*/

#include "GameEngine/game_head.h"
#include "Drawables/drawables_head.h"

static void draw_element(draw_elmt_t *elmt, sfRenderWindow *wind)
{
    if ((elmt->dtype & 128) != 0)
        return;
    switch (elmt->dtype) {
    case D_RECT:
        sfRenderWindow_drawRectangleShape(wind, elmt->draw->rect, NULL);
        break;
    case D_TEXT:
        sfRenderWindow_drawText(wind, elmt->draw->text, NULL);
        break;
    }
}

void draw_map(my_map_t *map, sfRenderWindow *wind)
{
    for (size_t i = 0; i < my_map_size(map); i++){
        draw_element((draw_elmt_t *)my_map_at(map, i), wind);
    }
}

void draw_vec(draw_elmt_t **vec, sfRenderWindow *wind)
{
    for (size_t i = 0; i < my_vector_get_size((size_t *)vec); i++){
        draw_element(vec[i], wind);
    }
}

draw_elmt_t *create_data_d(drawable_t *draw, unsigned char dtype)
{
    draw_elmt_t *elmt = malloc(sizeof(draw_elmt_t));

    elmt->draw = draw;
    elmt->dtype = dtype;
    return elmt;
}