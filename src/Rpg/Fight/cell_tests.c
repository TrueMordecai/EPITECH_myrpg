/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** cell_tests
*/

#include "Rpg/Fight/fight.h"

int cell_is_empty(cell_t *cell)
{
    return (!cell->entity && cell->physic == EMPTY);
}

int cell_is_occupied(cell_t *cell)
{
    return (cell->entity != NULL);
}

int cell_is_walkable(cell_t *cell)
{
    return (cell->physic == EMPTY);
}

int fight_is_pos_in(fight_t *fight, int pos)
{
    sfVector2i vec = fight_pos_to_vec(fight, pos, 0);

    if (fight_vec_to_pos(fight, vec) == -1)
        return 0;
    return 1;
}
