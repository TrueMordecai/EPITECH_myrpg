/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player_destroy
*/

#include <stdlib.h>
#include "Rpg/Entities/player.h"

void player_destroy(player_t *player)
{
    sfRectangleShape_destroy(player->rect);
    free(player);
}