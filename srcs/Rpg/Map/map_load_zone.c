/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map load zone
*/

#include "Rpg/rpg.h"
#include "My/my_strings.h"
#include "My/my_display.h"

zone_t *map_get_zone(map_t *map, char *name)
{
    size_t nb_zones = my_vector_get_size((size_t *)map->zones);

    for (size_t i = 0; i < nb_zones; i++) {
        if (my_strcmp(name, map->zones[i]->name) == 0)
            return map->zones[i];
    }
    return NULL;
}

void map_load_zone(map_t *map, char *name)
{
    zone_t *zone = map_get_zone(map, name);

    if (zone)
        map->current_zone = zone;
    else {
        zone = zone_create(map);
        map->current_zone = zone;
        zone_init_from_file(zone, name);
        my_vector_push((size_t **)&map->zones, (size_t)zone);
    }
    map->rpg->player->body = zone->player_body;
}