/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** zone create
*/

#include "Rpg/rpg.h"
#include "My/my_memory.h"

zone_t *zone_create(map_t *map)
{
    zone_t *zone = my_calloc(sizeof(zone_t), 0);

    zone->tiles_size = map->tiles_size;
    zone->map = map;
    zone->id = -1;
    zone->player_body = NULL;
    return zone;
}