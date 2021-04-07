/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_rect_buff
*/

#include "Rpg/Fight/fight.h"

void fight_reset_buff(fight_t *fight)
{
    int transparent = sfColor_toInteger(sfTransparent);
    int i = 0;

    while (sfColor_toInteger(sfRectangleShape_getFillColor(\
    fight->rect_buffer[i])) != transparent) {
        sfRectangleShape_setFillColor(fight->rect_buffer[i], sfTransparent);
        i++;
    }
}

static int get_first_i_unused(fight_t *fight)
{
    int transparent = sfColor_toInteger(sfTransparent);
    int i = 0;

    while (sfColor_toInteger(sfRectangleShape_getFillColor(\
        fight->rect_buffer[i])) != transparent)
        i++;
    return i;
}

void fight_place_rect(fight_t *fight, int pos, sfColor color, int test)
{
    sfRectangleShape *rect;
    sfColor new_color = sfColor_fromRGBA(color.r, color.g, color.b, 80);

    if (test == WALKABLE && !cell_is_walkable(&fight->grid[pos]))
        return;
    rect = fight->rect_buffer[get_first_i_unused(fight)];
    sfRectangleShape_setFillColor(rect, new_color);
    sfRectangleShape_setPosition(rect, fight_pos_to_world_vec(fight, pos));
}