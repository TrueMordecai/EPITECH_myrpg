/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone add special
*/

#include "Rpg/rpg.h"

void zone_add_special(zone_t *zone, sfVector2i pos, int special)
{
    if (!zone_assert_id(zone, pos.x, pos.y, NULL))
        return;
    zone->special[pos.x + pos.y * zone->size.x] = special + 1;
    switch (special + 1) {
        case SUB_DOOR:
            my_vector_push(
                (size_t **)&zone->sub_doors, pos.x + pos.y * zone->size.x);
            break;
        case EXT_DOOR:
            my_vector_push(
                (size_t **)&zone->ext_doors, pos.x + pos.y * zone->size.x);
            break;
        default: break;
    }
}
