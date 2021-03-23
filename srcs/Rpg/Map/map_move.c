/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map move
*/

#include "Rpg/rpg.h"

void map_move(map_t *map, sfVector2f offset)
{
    sfView_move(map->view, offset);
}