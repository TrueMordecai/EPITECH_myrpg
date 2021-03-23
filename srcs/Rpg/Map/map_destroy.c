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
    zone_destroy(map->current_zone);
    sfView_destroy(map->view);
    free(map);
}