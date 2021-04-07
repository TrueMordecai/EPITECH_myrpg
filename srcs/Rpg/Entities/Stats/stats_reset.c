/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stats_reset
*/

#include "Rpg/Entities/stats.h"

void stats_reset(stats_t *stats, int only_pa_pm)
{
    stats->current_pa = stats->pa;
    stats->current_pm = stats->pm;
    if (!only_pa_pm)
        stats->current_life = stats->life;
}