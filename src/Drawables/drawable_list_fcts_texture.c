/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Drawables lists fcts
*/

#include "Drawables/drawable.h"
#include "Drawables/drawables_create.h"

static void draw_element(drawable_t *element, sfRenderTexture *texture)
{
    if ((element->dtype & 0x80) != 0)
        return;
    switch (element->dtype) {
        case D_RECT:
            sfRenderTexture_drawRectangleShape(
                texture, element->data.rect, NULL);
            break;
        case D_TEXT:
            sfRenderTexture_drawText(texture, element->data.text, NULL);
            break;
        default: break;
    }
}

void draw_from_map_texture(my_hash_map_t *map, sfRenderTexture *texture)
{
    my_hash_map_iter_t iter;

    my_hash_map_iter_init(&iter, map);
    while (my_hash_map_iter_next(&iter))
        draw_element(*(drawable_t **)iter.value, texture);
}

void draw_from_array_texture(
    size_t count, drawable_t *elements[count], sfRenderTexture *texture)
{
    for (size_t i = 0; i < count; ++i)
        draw_element(elements[i], texture);
}
