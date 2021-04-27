/*
** EPITECH PROJECT, 2020
** My editor
** File description:
** is in bounds
*/

#include <SFML/Graphics.h>

int is_in_bounds(sfVector2f pos, sfVector2f item_pos, sfVector2f item_size)
{
    return (pos.x >= item_pos.x && pos.x <= item_pos.x + item_size.x && \
    pos.y >= item_pos.y && pos.y <= item_pos.y + item_size.y);
}

int is_in_bounds_i(sfVector2i pos, sfVector2i item_pos, \
sfVector2i item_size, int strict)
{
    if (strict){
        return (pos.x >= item_pos.x && pos.x < item_pos.x + item_size.x && \
        pos.y >= item_pos.y && pos.y < item_pos.y + item_size.y);
    }
    return (pos.x >= item_pos.x && pos.x <= item_pos.x + item_size.x && \
    pos.y >= item_pos.y && pos.y <= item_pos.y + item_size.y);
}

int is_in_rect(sfVector2f pos, sfFloatRect rect)
{
    return (pos.x >= rect.left && pos.x <= rect.left + rect.width && \
    pos.y >= rect.top && pos.y <= rect.top + rect.height);
}