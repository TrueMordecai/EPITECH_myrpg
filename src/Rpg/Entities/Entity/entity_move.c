/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_move
*/

#include "Rpg/Entities/player.h"
#include "Rpg/Entities/entity.h"
#include "Rpg/Fight/fight.h"

static void move_player(player_t *player)
{
    sfVector2i pos = fight_pos_to_vec(player->entity->fight, \
    player->entity->pos, 1);

    player->body->pos.x = pos.x;
    player->body->pos.y = pos.y;
}

static void move_rect(entity_t *entity)
{
    sfVector2f pos = fight_pos_to_world_vec(entity->fight, entity->pos);

    pos.y -= 32;
    sfRectangleShape_setPosition(entity->rect, pos);
}

void entity_move(entity_t *entity)
{
    int size_move = 0;

    if (!entity->move_path)
        return;
    for (int i = 0; entity->move_path[i] != END_ARRAY; i++)
        size_move++;
    size_move = MIN(size_move - 1, entity->stats->current_pm);
    entity->fight->grid[entity->pos].entity = NULL;
    entity->pos = entity->move_path[size_move];
    entity->fight->grid[entity->pos].entity = entity;
    entity->stats->current_pm -= size_move;
    entity_update_move_possibilities(entity);
    if (entity->type == PLAYER)
        move_player(entity->datas);
    else
        move_rect(entity);
}