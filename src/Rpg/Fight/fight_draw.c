/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_draw
*/

#include "Rpg/Fight/fight.h"

void fight_draw(fight_t *fight, sfRenderWindow *wind)
{
    sfUint32 transparent = sfColor_toInteger(sfTransparent);
    int i = 0;

    while (sfColor_toInteger(sfRectangleShape_getFillColor(\
    fight->rect_buffer[i])) != transparent) {
        sfRenderWindow_drawRectangleShape(wind, fight->rect_buffer[i], NULL);
        i++;
    }
    for (int x = 0; x < fight->size.x; x++) {
        for (int y = 0; y < fight->size.y; y++)
            entity_draw(fight->grid[x + y * fight->size.x].entity, wind);
    }
}