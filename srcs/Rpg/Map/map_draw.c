/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map draw
*/

#include "Rpg/rpg.h"

void map_draw(map_t *map)
{
    zone_draw(map->current_zone, map->rpg->wind);
}