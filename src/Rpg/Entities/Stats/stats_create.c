/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stats_create
*/

#include <stdlib.h>
#include "Rpg/Entities/stats.h"

stats_t *stats_create(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->life = 100;
    stats->pa = 6;
    stats->pm = 3;
    stats->current_life = 100;
    stats->current_pa = 6;
    stats->current_pm = 3;
    for (int i = 0; i < 4; i++) {
        stats->elements[i] = 0;
        stats->resistances[i] = 0;
    }
    return stats;
}