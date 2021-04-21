/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stats_apply_effects
*/

#include "Rpg/Entities/entity.h"

void stats_add_effect(stats_t *stats, effect_t *effect)
{
    my_vec_push(&stats->effects, effect);
    if (!(effect->spell->type & EFFECT_BOOST))
        return;
    stats->life += effect->spell->buff.life;
    stats->current_pa += effect->spell->buff.pa;
    stats->current_pm += effect->spell->buff.pm;
    for (int j = 0; j < 4; j++) {
        stats->elements[j] += effect->spell->buff.elements[j];
        stats->resistances[j] += effect->spell->buff.resistances[j];
    }
}

void apply_effect_turn_start(stats_t *stats)
{
    effect_t *effect;

    for (size_t i = 0; i < stats->effects.length; i++) {
        effect = ((effect_t *)stats->effects.data) + i;
        if (!(effect->spell->type & EFFECT_BOOST))
            continue;
        stats->current_pa += effect->spell->buff.pa;
        stats->current_pm += effect->spell->buff.pm;
    }
}

void apply_effect_turn_ends(stats_t *stats)
{
    effect_t *effect;

    for (size_t i = 0; i < stats->effects.length; i++) {
        effect = ((effect_t *)stats->effects.data) + i;
        if (!(effect->spell->type & EFFECT_DAMAGE))
            continue;
        for (int j = 0; j < 4; j++)
            stats->life -= effect->spell->damages[i]
                * (1 + effect->from->stats->elements[i] / 30.f);
    }
}

void update_effect_turn_ends(stats_t *stats)
{
    effect_t *effect;

    apply_effect_turn_ends(stats);
    for (size_t i = 0; i < stats->effects.length; i++) {
        effect = ((effect_t *)stats->effects.data) + i;
        effect->lifetime--;
        if (effect->lifetime <= 0)
            my_vec_remove(&stats->effects, NULL, i--);
    }
}