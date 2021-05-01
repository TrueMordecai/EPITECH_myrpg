/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map destroy
*/

#include <stdlib.h>
#include "Rpg/Map/map.h"

static void map_destroy_zone(void *element)
{
    zone_t **zone = element;

    zone_destroy(*zone);
    zone = NULL;
}

void map_destroy(map_t *map)
{
    my_vec_free(&map->zones, &map_destroy_zone);
    sfView_destroy(map->view);
    map->view = NULL;
    free(map);
}
