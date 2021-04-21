/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_move
*/

#include <libmy/printf.h>

#include "Rpg/rpg.h"
#include "Rpg/Entities/player.h"
#include "Rpg/Entities/entity.h"
#include "Rpg/Fight/fight.h"

static void move_player(player_t *player, sfVector2f pos)
{
    sfVector2i vec_i;

    if ((int)pos.x == -1 && (int)pos.y == -1) {
        vec_i = fight_pos_to_vec(player->entity->fight, \
        player->entity->pos, 1);
        pos = (sfVector2f){vec_i.x, vec_i.y};
    } else {
        pos.x /= M_TO_PX;
        pos.y /= M_TO_PX;
    }
    player->body->pos.x = pos.x;
    player->body->pos.y = pos.y;
}

static void move_rect(entity_t *entity, sfVector2f pos)
{
    if ((int)pos.x == -1 && (int)pos.y == -1)
        pos = fight_pos_to_world_vec(entity->fight, entity->pos);
    sfRectangleShape_setPosition(entity->rect, pos);
}

void entity_update_sprite_pos(entity_t *entity, sfVector2f pos)
{
    if (entity->type == PLAYER)
        move_player(entity->datas, pos);
    else
        move_rect(entity, pos);
}

void entity_move(entity_t *entity, int update_sprite)
{
    int size_move = 0;

    if (!entity->move_path)
        return;
    size_move = MIN(entity->move_path->length - 1, \
    (size_t)entity->stats->current_pm);
    entity->fight->grid[entity->pos].entity = NULL;
    entity->pos = MY_VEC_GET_ELEM(int, entity->move_path, size_move);
    entity->fight->grid[entity->pos].entity = entity;
    if (update_sprite)
        entity_update_sprite_pos(entity, (sfVector2f){-1, -1});
    else
        entity_add_action(entity, MOVE);
    entity->stats->current_pm -= size_move;
    entity_update_move_possibilities(entity);
}