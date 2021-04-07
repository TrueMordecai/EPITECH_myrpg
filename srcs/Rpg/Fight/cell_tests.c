/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** cell_tests
*/

#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

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