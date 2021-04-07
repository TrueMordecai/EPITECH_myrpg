/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_move
*/

#include "Rpg/Entities/player.h"
#include "Rpg/Entities/entity.h"
#include "Rpg/Fight/fight.h"

static int get_manhattan_dist(fight_t *fight, int p1, int p2)
{
    sfVector2i v1 = fight_pos_to_vec(fight, p1, 0);
    sfVector2i v2 = fight_pos_to_vec(fight, p2, 0);

    return abs(v1.x - v2.x) + abs(v1.y - v2.y);
}

static void move_player(player_t *player)
{
    sfVector2i pos = fight_pos_to_vec(player->entity->fight, \
    player->entity->pos, 1);

    player->body->pos.x = pos.x;
    player->body->pos.y = pos.y;
}

void entity_move(entity_t *entity, int new_pos)
{
    int dist = get_manhattan_dist(entity->fight, entity->pos, new_pos);

    if (dist > entity->stats->pm)
        return;
    entity->pos = new_pos;
    if (entity->type == PLAYER)
        move_player(entity->datas);
}