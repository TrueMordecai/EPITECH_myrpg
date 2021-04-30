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

    stats_init_from_level(stats, 1);
    stats->current_life = 50;
    stats->current_pa = 6;
    stats->current_pm = 3;
    my_vec_init(&stats->effects, sizeof(effect_t));
    return stats;
}