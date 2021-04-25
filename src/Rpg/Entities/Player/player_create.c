/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player create
*/

#include <libmy/memory/alloc.h>

#include "Rpg/rpg.h"

player_t *player_create(rpg_t *rpg)
{
    player_t *player = my_calloc(1, sizeof(player_t));
    sfRectangleShape *rect;

    player->pos = (sfVector2f){6 * M_TO_PX, 6 * M_TO_PX};
    rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){32, 32});
    player->entity = entity_create(player, PLAYER, ALLIES, 0);
    player->entity->rect = rect;
    player->entity->stats = stats_create();
    player->rpg = rpg;
    player->entity->name = "Inspector";
    sfRectangleShape_setTexture(player->entity->rect,
        get_texture(&rpg->state->game_data->assets, player->entity->name),
        true);
    animations_reset(&player->entity->anim);
    entity_init_spells(player->entity, rpg);
    return player;
}
