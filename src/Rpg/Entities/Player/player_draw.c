/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player draw
*/

#include "Rpg/rpg.h"

void player_draw(player_t *player, sfRenderWindow *wind)
{
    sfRenderWindow_drawRectangleShape(wind, player->entity->rect, NULL);
}