/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_draw
*/

#include "Rpg/Fight/fight.h"

void entity_draw(entity_t *entity, sfRenderWindow *wind)
{
    if (!entity || !entity->rect || !entity->alive)
        return;
    sfRenderWindow_drawRectangleShape(wind, entity->rect, NULL);
}