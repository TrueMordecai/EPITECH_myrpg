/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone add special
*/

#include "Rpg/rpg.h"

void zone_add_special(zone_t *zone, sfVector2i pos, int special)
{
    zone->special[pos.x + pos.y * zone->size.x] = special;
}