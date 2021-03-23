/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player update.c
*/

#include "Rpg/Entities/player.h"

void player_update(player_t *player, float dt)
{
    sfVector2f offset = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        offset.y = -1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        offset.y = 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        offset.x = -1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        offset.x = 1;
    offset.x *= dt * 200;
    offset.y *= dt * 200;
    player->pos.x += offset.x;
    player->pos.y += offset.y;
    sfRectangleShape_setPosition(player->rect, player->pos);
}