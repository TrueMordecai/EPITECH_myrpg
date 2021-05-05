/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** stats_apply_effects
*/

#include <libmy/printf.h>
#include <limits.h>

#include "Rpg/Entities/entity.h"

static void check_max_cumul(stats_t *stats, effect_t *cast_effect)
{
    effect_t *effect;
    int min_lifetime = INT_MAX;
    int min_id = -1;
    int count = 0;

    for (size_t i = 0; i < stats->effects.length; i++) {
        effect = ((effect_t *)stats->effects.data) + i;
        if (effect->spell != cast_effect->spell)
            continue;
        count++;
        if (effect->lifetime < min_lifetime) {
            min_lifetime = effect->lifetime;
            min_id = i;
        }
    }
    if (count >= cast_effect->spell->max_cumul)
        stats_remove_effect(stats, min_id, 1);
}

void stats_add_effect(stats_t *stats, effect_t *effect)
{
    check_max_cumul(stats, effect);
    my_vec_push(&stats->effects, effect);
    if (!(effect->spell->type & EFFECT_BOOST))
        return;
    stats->current_life += effect->spell->buff.life;
    stats->life += effect->spell->buff.life;
    stats->current_pa += effect->spell->buff.pa;
    stats->current_pm += effect->spell->buff.pm;
    for (int j = 0; j < 4; j++) {
        stats->elements[j] += effect->spell->buff.elements[j];
        stats->resistances[j] += effect->spell->buff.resistances[j];
    }
}

void stats_remove_effect(stats_t *stats, int effect_id, int debuff)
{
    effect_t *effect = ((effect_t *)stats->effects.data) + effect_id;

    if ((size_t)effect_id >= stats->effects.length || effect_id < 0 || !effect)
        return;
    if ((effect->spell->type & EFFECT_BOOST)) {
        stats->current_life -= effect->spell->buff.life;
        stats->life -= effect->spell->buff.life;
        if (debuff) {
            stats->current_pm -= effect->spell->buff.pm;
            stats->current_pa -= effect->spell->buff.pa;
        }
        for (int j = 0; j < 4; j++) {
            stats->elements[j] -= effect->spell->buff.elements[j];
            stats->resistances[j] -= effect->spell->buff.resistances[j];
        }
    }
    my_vec_remove(&stats->effects, NULL, effect_id);
}
