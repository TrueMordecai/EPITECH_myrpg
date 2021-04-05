/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map destroy
*/

#include <stdlib.h>
#include "Rpg/Map/map.h"

void map_destroy(map_t *map)
{
    size_t nb_zones = my_vector_get_size((size_t *)map->zones);

    for (size_t i = 0; i < nb_zones; i++)
        zone_destroy(map->zones[i]);
    my_vector_free((size_t **)&map->zones);
    sfView_destroy(map->view);
    free(map);
}