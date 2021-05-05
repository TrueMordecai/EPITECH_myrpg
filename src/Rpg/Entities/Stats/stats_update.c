/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** stats_update
*/

#include "Rpg/Entities/stats.h"
#include "functions.h"

int stats_update(stats_t *stats)
{
    if (!stats)
        return 0;
    if (stats->current_life > stats->life)
        stats->current_life = stats->life;
    CLAMP_ASSIGN(stats->current_life, 0, stats->life);
    return (stats->current_life == 0);
}
