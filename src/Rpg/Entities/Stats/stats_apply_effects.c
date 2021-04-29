/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stats_apply_effects
*/

#include <libmy/printf.h>
#include <limits.h>

#include "Rpg/Entities/entity.h"

void stats_clear_effects(stats_t *stats)
{
    size_t length = stats->effects.length;

    for (int i = 0; i < length; i++)
        stats_remove_effect(stats, 0, 1);
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
            stats->current_life -= effect->spell->damages[j]
                * (1 + effect->from->stats->elements[j] / 30.f);
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
            stats_remove_effect(stats, i--, 0);
    }
}