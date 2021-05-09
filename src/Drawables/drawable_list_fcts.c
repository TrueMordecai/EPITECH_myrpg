/*
** EPITECH PROJECT, 2021
** Game Engine
** File description:
** Drawables lists functions
*/

#include <stdlib.h>

#include "Drawables/drawable.h"
#include "Drawables/drawables_create.h"

static void draw_element(drawable_t *elmt, sfRenderWindow *window)
{
    if ((elmt->dtype & 0x80) != 0)
        return;
    switch (elmt->dtype) {
        case D_RECT:
            sfRenderWindow_drawRectangleShape(window, elmt->data.rect, NULL);
            break;
        case D_TEXT:
            sfRenderWindow_drawText(window, elmt->data.text, NULL);
            break;
        default: break;
    }
}

void draw_from_map(my_hash_map_t const *map, sfRenderWindow *window)
{
    my_hash_map_iter_t iter;

    my_hash_map_iter_init(&iter, map);
    while (my_hash_map_iter_next(&iter))
        draw_element(*(drawable_t **)iter.value, window);
}

void draw_from_array(
    size_t count, drawable_t *elements[count], sfRenderWindow *window)
{
    for (size_t i = 0; i < count; ++i)
        draw_element(elements[i], window);
}
