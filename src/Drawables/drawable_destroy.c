/*
** EPITECH PROJECT, 2021
** Duck hunt
** File description:
** delete drawable
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>
#include <libmy/collections/hash_map.h>

#include "Drawables/drawable.h"

void drawable_destroy(drawable_t *drawable)
{
    switch (drawable->dtype) {
        case D_RECT: sfRectangleShape_destroy(drawable->data.rect); break;
        case D_TEXT: sfText_destroy(drawable->data.text); break;
        default: break;
    }
    drawable->data.ptr = NULL;
    drawable->dtype = -1;
}
