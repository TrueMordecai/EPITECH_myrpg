/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stats_init
*/

#include "Rpg/Entities/stats.h"

void stats_init(stats_t *stats, int *elements, int *resistances, int life)
{
    for (int i = 0; i < 4; i++) {
        stats->elements[i] = elements[i];
        stats->resistances[i] = resistances[i];
    }
    stats->life = life;
}

void stats_init_pa_pm(stats_t *stats, int pa, int pm)
{
    stats->pa = pa;
    stats->pm = pm;
}