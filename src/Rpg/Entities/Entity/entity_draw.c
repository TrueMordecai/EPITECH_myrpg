/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** entity_draw
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"

void entity_draw_dead(entity_t *entity, sfRenderWindow *wind)
{
    sfColor color = sfRectangleShape_getFillColor(entity->rect);

    if (entity->alive <= -256)
        return;
    color.a = 255 + entity->alive;
    sfRectangleShape_setFillColor(entity->rect, color);
    sfRenderWindow_drawRectangleShape(wind, entity->rect, NULL);
}

void entity_draw(entity_t *entity, sfRenderWindow *wind)
{
    if (!entity || !entity->rect)
        return;
    if (entity->alive <= 0)
        entity_draw_dead(entity, wind);
    else
        sfRenderWindow_drawRectangleShape(wind, entity->rect, NULL);
}
