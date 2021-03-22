/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Drawable - create
*/

#ifndef DRAWABLES_CREATES_H
#define DRAWABLES_CREATES_H

#include <SFML/Graphics.h>

sfRectangleShape *create_rect_shape(sfTexture *texture, \
sfVector2f size, sfVector2f pos, sfVector2f scale);
sfText *create_text(sfFont *font, wchar_t const *str, \
unsigned int character_size, sfVector2f pos);

#endif /* !DRAWABLES_CREATES_H */