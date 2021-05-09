/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** stats_apply_effects
*/

#include <libmy/printf.h>
#include <limits.h>

#include "Rpg/Entities/entity.h"

void stats_clear_effects(stats_t *stats)
{
    size_t length = stats->effects.length;

    for (size_t i = 0; i < length; i++)
        stats_remove_effect(stats, 0, 1);
}

void apply_effect_turn_start(stats_t *stats)
{
    effect_t *effect;

    for (size_t i = 0; i < stats->effects.length; i++) {
        effect = ((effect_t *)stats->effects.data) + i;
        if (!(effect->spell->type & EFFECT_BOOST))
            continue;
        stats->current_pa += effect->spell->buff.ap;
        stats->current_pm += effect->spell->buff.mp;
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
            stats->current_life -= stats_compute_damages(
                effect->from->stats, stats, j, effect->spell->damages[j]);
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
