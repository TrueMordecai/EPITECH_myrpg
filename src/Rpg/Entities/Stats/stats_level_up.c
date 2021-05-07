/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** stats_level_up
*/

#include "Rpg/Entities/stats.h"
#include "functions.h"

static void stats_apply_level_up_bonus(stats_t *stats)
{
    int bonus_stat = get_randi(0, 9);

    if (bonus_stat != 9) {
        if (bonus_stat < 4)
            stats->elements[bonus_stat % 4] += get_randi(1, 5);
        else
            stats->resistances[bonus_stat % 4] += get_randi(1, 3);
    } else
        stats->life += get_randi(1, 10);
}

void stats_init_from_level(stats_t *stats, int level)
{
    level = MAX(1, level);
    stats->level = level;
    stats->xp = 0;
    for (int i = 0; i < 4; i++) {
        stats->elements[i] = (level - 1) * 5;
        stats->resistances[i] = (level - 1) * 3;
    }
    stats->life = 50 + (level - 1) * 10;
    stats_init_pa_pm(stats, 6, 3);
    for (int i = 0; i < level - 1; i++)
        stats_apply_level_up_bonus(stats);
}

void stats_level_up(stats_t *stats)
{
    stats->level++;
    stats->xp -= XP_TO_LEVEL_UP;
    stats->life += 10;
    for (int i = 0; i < 4; i++) {
        stats->elements[i] += 5;
        stats->resistances[i] += 3;
    }
    stats_apply_level_up_bonus(stats);
}

void stats_gain_xp(stats_t *stats, int xp)
{
    stats->xp += xp;
    while (stats->xp >= XP_TO_LEVEL_UP)
        stats_level_up(stats);
}

void stats_lose_xp(stats_t *stats, int xp)
{
    stats->xp -= xp;
    while (stats->xp < 0 && stats->level > 1) {
        stats->xp += XP_TO_LEVEL_UP;
        stats->level--;
        stats->life -= 10;
        for (int i = 0; i < 4; i++) {
            stats->elements[i] -= 5;
            stats->resistances[i] -= 3;
        }
    }
    if (stats->xp < 0 && stats->level == 1)
        stats->xp = 0;
}