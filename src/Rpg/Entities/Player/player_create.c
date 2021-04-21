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
    sfRectangleShape *rect;

    player->pos = (sfVector2f){6 * M_TO_PX, 6 * M_TO_PX};
    rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){32, 32});
    player->entity = entity_create(player, PLAYER, ALLIES, 0);
    player->entity->rect = rect;
    player->entity->stats = stats_create();
    return player;
}
