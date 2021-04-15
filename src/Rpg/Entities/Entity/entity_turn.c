/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_turn
*/

#include <libmy/printf.h>
#include "Rpg/Fight/fight.h"

void entity_start_turn(entity_t *entity)
{
    stats_reset(entity->stats, 1);
    entity_update_move_possibilities(entity);
    entity_update_spell_sight(entity);
}

void entity_end_turn(entity_t *entity)
{
    if (!entity->actions.length)
        return;
    for (size_t i = 0; i < entity->actions.length; i++)
        entity_force_end_action(entity, my_vec_get(&entity->actions, i));
    entity->actions.length = 0;
}