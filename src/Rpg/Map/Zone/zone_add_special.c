/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone add special
*/

#include "Rpg/rpg.h"

void zone_add_special(zone_t *zone, sfVector2i pos, int special)
{
    int id;

    if (!zone_assert_id(zone, pos.x, pos.y, NULL))
        return;
    id = pos.x + pos.y * zone->size.x;
    zone->special[id] = special + 1;
    switch (special + 1) {
        case SUB_DOOR: my_vec_push(&zone->sub_doors, &id); break;
        case EXT_DOOR: my_vec_push(&zone->ext_doors, &id); break;
        default: break;
    }
}
