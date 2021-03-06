/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** entity_turn
*/

#include <libmy/printf.h>
#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

void entity_update_alive(entity_t *entity)
{
    if (stats_update(entity->stats)) {
        entity->alive = 0;
        play_sound(
            &entity->fight->rpg->state->game_data->audio, "entity_death");
        sfRectangleShape_setTextureRect(
            entity->rect, (sfIntRect){0, 96, 16, 16});
    }
}

static void reset_spells_turn(entity_t *entity)
{
    spell_base_t *base;

    for (size_t i = 0; i < entity->spells.length; i++) {
        base = MY_VEC_GET_ELEM(spell_base_t *, &entity->spells, i);
        base->cast_left = base->turn_limit;
    }
}

void entity_start_turn(entity_t *entity, int first)
{
    reset_spells_turn(entity);
    stats_reset(entity->stats, 1);
    apply_effect_turn_start(entity->stats);
    entity_update_move_possibilities(entity);
    entity_update_spell_sight(entity);
    if (entity->team == ALLIES || first)
        return;
    entity_compute_move(entity);
}

void entity_end_turn(entity_t *entity)
{
    update_effect_turn_ends(entity->stats);
    entity_update_alive(entity);
    if (!entity->actions.length)
        return;
    for (size_t i = 0; i < entity->actions.length; i++)
        entity_force_end_action(entity, my_vec_get(&entity->actions, i));
    entity->actions.length = 0;
}
