/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** fight_pathfinding_2
*/

#include <libmy/collections/vec.h>

#include "Rpg/Fight/fight.h"

int get_heuristic_cost(fight_t *fight, int pos_a, int pos_b);

static int is_next_pos_valid(fight_t *fight, int current, int diff)
{
    int y = fight_pos_to_vec(fight, current, 0).y;

    if (!fight_is_pos_in(fight, current + diff))
        return 0;
    if (abs(diff) == 1 && fight_pos_to_vec(fight, current + diff, 0).y != y)
        return 0;
    return 1;
}

int get_next_pos(fight_t *fight, int current, int dir)
{
    int y_diff = fight->size.x;
    int diff;

    if (dir % 2 == 0)
        diff = (dir) ? -1 : 1;
    else
        diff = (dir == 1) ? -y_diff : y_diff;
    if (!is_next_pos_valid(fight, current, diff))
        return INEXISTING;
    return current + diff;
}

int get_heuristic_cost(fight_t *fight, int pos_a, int pos_b)
{
    int ax = pos_a % fight->size.x;
    int ay = pos_a / fight->size.x;
    int bx = pos_b % fight->size.x;
    int by = pos_b / fight->size.x;

    return (abs(ax - bx) + abs(ay - by));
}
