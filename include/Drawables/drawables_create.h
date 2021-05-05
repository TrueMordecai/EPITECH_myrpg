/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Drawables lists
*/

#ifndef GE_DRAWABLES_H
#define GE_DRAWABLES_H

#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>

sfRectangleShape *create_rect_shape(sfTexture *texture, \
sfVector2f size, sfVector2f pos, sfVector2f scale);
sfText *create_text(sfFont *font, wchar_t const *str, \
unsigned int character_size, sfVector2f pos);

#endif
