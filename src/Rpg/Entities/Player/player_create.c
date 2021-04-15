/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player create
*/

#include <libmy/memory/alloc.h>

#include "Rpg/rpg.h"

player_t *player_create(void)
{
    player_t *player = my_calloc(1, sizeof(player_t));

    player->pos = (sfVector2f){6 * M_TO_PX, 6 * M_TO_PX};
    player->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(player->rect, (sfVector2f){32, 64});
    sfRectangleShape_setFillColor(player->rect, sfWhite);
    sfRectangleShape_setOutlineColor(player->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(player->rect, -2);
    player->entity = entity_create(player, PLAYER, ALLIES, 0);
    player->entity->stats = stats_create();
    return player;
}
