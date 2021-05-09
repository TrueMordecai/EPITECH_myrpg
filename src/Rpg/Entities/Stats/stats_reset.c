/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** stats_reset
*/

#include <libmy/printf.h>

#include "Rpg/Entities/stats.h"

void stats_reset(stats_t *stats, int only_pa_pm)
{
    if (!only_pa_pm) {
        stats_clear_effects(stats);
        stats->current_life = stats->life;
    }
    stats->current_pa = stats->ap;
    stats->current_pm = stats->mp;
}

void stats_display(stats_t *stats)
{
    my_printf("Display stats:\n   Life %d/%d\n   AP %d/%d\n   MP %d/%d\n",
        stats->current_life, stats->life, stats->current_pa, stats->ap,
        stats->current_pm, stats->mp);
    my_printf("   Earth %d\n   Fire %d\n   Water %d\n   Wind %d\n",
        stats->elements[EARTH], stats->elements[FIRE], stats->elements[WATER],
        stats->elements[WIND]);
    my_printf(
        "   Earth Res %d\n   Fire Res %d\n   Water Res %d\n   Wind Res %d\n",
        stats->resistances[EARTH], stats->resistances[FIRE],
        stats->resistances[WATER], stats->resistances[WIND]);
    my_printf("   %ld effects\n\n", stats->effects.length);
}
