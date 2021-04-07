/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_draw
*/

#include "Rpg/Fight/fight.h"

void fight_draw(fight_t *fight, sfRenderWindow *wind)
{
    int transparent = sfColor_toInteger(sfTransparent);
    int i = 0;

    while (sfColor_toInteger(sfRectangleShape_getFillColor(\
    fight->rect_buffer[i])) != transparent) {
        sfRenderWindow_drawRectangleShape(wind, fight->rect_buffer[i], NULL);
        i++;
    }
}