/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player draw
*/

#include "Rpg/Entities/player.h"

void player_draw(player_t *player, sfRenderWindow *wind)
{
    sfRenderWindow_drawRectangleShape(wind, player->rect, NULL);
}