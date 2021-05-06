/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** entity_update
*/

#include <libmy/printf.h>
#include <stdio.h>
#include "Rpg/Fight/fight.h"

void update_anim(entity_t *entity, sfVector2f delta)
{
    int anim_id = 0;

    if (delta.x)
        anim_id = 2 + (delta.x > 0);
    if (delta.y)
        anim_id = 0 + (delta.y < 0);
    entity->anim.paused = 0;
    if (entity->anim.current_anim != anim_id)
        animations_set_animation(&entity->anim, anim_id);
}

void action_move_update(entity_t *entity, float dt, action_t *act)
{
    sfVector2f start = fight_pos_to_world_vec(
        entity->fight, MY_VEC_GET_ELEM(int, &act->move.path, act->move.i));
    sfVector2f end = fight_pos_to_world_vec(
        entity->fight, MY_VEC_GET_ELEM(int, &act->move.path, act->move.i + 1));
    sfVector2f delta = {end.x - start.x, end.y - start.y};
    sfVector2f pos = {start.x + delta.x * act->move.progress,
        start.y + delta.y * act->move.progress};

    update_anim(entity, delta);
    act->move.progress += dt * 5;
    entity_update_sprite_pos(entity, pos);
    if (act->move.progress > 1.0) {
        act->move.progress = MIN(act->move.progress, 1);
        action_move_update(entity, 0, act);
        act->move.progress = 0;
        if ((++act->move.i) == act->move.len_path) {
            my_vec_free(&act->move.path, NULL);
            my_vec_remove(&entity->actions, NULL, 0);
            animations_pause(&entity->anim);
        }
    }
}

void action_attack_update(entity_t *entity, float dt, action_t *act)
{
    sfIntRect rect;

    if (act->attack.progress == 0)
        entity_attack(entity, act);
    act->attack.progress += dt * 3;
    if (act->attack.progress > 0.5) {
        rect = sfRectangleShape_getTextureRect(entity->rect);
        rect.top = 0;
        sfRectangleShape_setTextureRect(entity->rect, rect);
    }
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
    animations_update(&entity->anim, dt);
    if (entity->alive <= 0 && entity->alive > -256)
        entity->alive -= dt * 250;
    if (!playing || entity->alive <= 0)
        return;
    if (entity->state == IDLE && entity->team == ALLIES) {
        if (entity->spell_select < 0) {
            entity_draw_move_possibilities(entity, 0);
            entity_draw_move_path(entity, 1);
        } else {
            entity_draw_spell_sight(entity, 0);
            entity_draw_spell_cell(entity);
        }
    }
    if (entity->actions.length)
        entity_update_actions(entity, dt);
    (void)dt;
}
