/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stats_apply_effects
*/

#include <libmy/printf.h>
#include <limits.h>

#include "Rpg/Entities/entity.h"

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