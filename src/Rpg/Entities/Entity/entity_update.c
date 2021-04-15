/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_update
*/

#include <stdio.h>
#include <libmy/printf.h>
#include "Rpg/Fight/fight.h"

void action_move_update(entity_t *entity, float dt, action_t *act)
{
    sfVector2f start = fight_pos_to_world_vec(entity->fight, \
    MY_VEC_GET_ELEM(int, &act->move.path, act->move.i));
    sfVector2f end = fight_pos_to_world_vec(entity->fight, \
    MY_VEC_GET_ELEM(int, &act->move.path, act->move.i + 1));
    sfVector2f delta = {end.x - start.x, end.y - start.y};
    sfVector2f pos = {start.x + delta.x * act->move.progress, \
        start.y + delta.y * act->move.progress};

    act->move.progress += dt * 5;
    entity_update_sprite_pos(entity, pos);
    if (act->move.progress > 1.0) {
        act->move.progress = MIN(act->move.progress, 1);
        action_move_update(entity, 0, act);
        act->move.progress = 0;
        act->move.i++;
        if (act->move.i == act->move.len_path) {
            my_vec_free(&act->move.path, NULL);
            my_vec_remove(&entity->actions, NULL, 0);
        }
    }
}

void action_attack_update(entity_t *entity, float dt, action_t *act)
{
    act->attack.progress += dt * 3;
    if (act->attack.progress > 1.0)
        my_vec_remove(&entity->actions, NULL, 0);
}

void entity_update_actions(entity_t *entity, float dt)
{
    action_t *act = (action_t *)my_vec_get(&entity->actions, 0);

    if (act->action_type == MOVE)
        action_move_update(entity, dt, act);
    if (act->action_type == ATTACK)
        action_attack_update(entity, dt, act);
}

void entity_update(entity_t *entity, float dt, int playing)
{
    if (!playing)
        return;
    if (entity->state == IDLE) {
        if (entity->spell_select < 0) {
            entity_draw_move_possibilities(entity, 0);
            entity_draw_move_path(entity, 1);
        } else
            entity_draw_spell_sight(entity, 0);
    }
    if (entity->actions.length)
        entity_update_actions(entity, dt);
}