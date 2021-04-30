/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stats_init
*/

#include "Rpg/Entities/stats.h"
#include "functions.h"

void stats_init_blank(stats_t *stats)
{
    stats->life = 0;
    stats->pm = 0;
    stats->pa = 0;
    stats->current_life = 0;
    stats->current_pa = 0;
    stats->current_pm = 0;
    stats->level = 1;
    for (int i = 0; i < 4; i++) {
        stats->elements[i] = 0;
        stats->resistances[i] = 0;
    }
}

void stats_init_from_level(stats_t *stats, int level)
{
    stats->level = level;
    for (int i = 0; i < 4; i++) {
        stats->elements[i] = level * 5 + get_randi(-5, 15);
        stats->resistances[i] = level * 3 + get_randi(-2, 5);
    }
    stats->life = 50 + level * 10 + get_randi(-15, 15);
    stats_init_pa_pm(stats, 6, 3);
}

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