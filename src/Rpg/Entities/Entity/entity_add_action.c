/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_add_action
*/

#include "Rpg/Fight/fight.h"

static void init_move_action(entity_t *entity, action_t *act)
{
    act->move.i = 0;
    act->move.progress = 0;
    act->move.len_path =
        MIN(entity->move_path->length - 1, (size_t)entity->stats->current_pm);
    if (act->move.len_path == 0)
        return;
    my_vec_copy(&act->move.path, entity->move_path);
    my_vec_push(&entity->actions, act);
}

static void init_attack_action(
    entity_t *entity, action_t *act, spell_base_t *spell)
{
    act->attack.progress = 0;
    act->attack.spell = spell;
    my_vec_push(&entity->actions, act);
}

action_t *entity_add_action(
    entity_t *entity, enum actions_e action_type, void *data)
{
    action_t action;

    action.action_type = action_type;
    if (action_type == MOVE)
        init_move_action(entity, &action);
    if (action_type == ATTACK)
        init_attack_action(entity, &action, data);
    return ((action_t *)entity->actions.data + entity->actions.length - 1);
}