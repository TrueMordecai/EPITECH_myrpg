/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Drawable - create drawable
*/

#include "Drawables/drawables_create.h"

sfRectangleShape *create_rect_shape(sfTexture *texture, \
sfVector2f size, sfVector2f pos, sfVector2f scale)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setTexture(rect, texture, 1);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setScale(rect, scale);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}

sfText *create_text(sfFont *font, wchar_t const *str, \
unsigned int character_size, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, character_size);
    sfText_setUnicodeString(text, (sfUint32 *)str);
    return text;
}