/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_turn
*/

#include "Rpg/Fight/fight.h"

void entity_start_turn(entity_t *entity)
{
    stats_reset(entity->stats, 1);
    entity_update_move_possibilities(entity);
}

void entity_end_turn(entity_t *entity)
{
}