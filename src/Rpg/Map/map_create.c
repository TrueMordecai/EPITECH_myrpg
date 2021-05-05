/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map create
*/

#include <libmy/memory/alloc.h>

#include "Rpg/rpg.h"

map_t *map_create(rpg_t *rpg)
{
    map_t *map = my_calloc(1, sizeof(map_t));

    map->nb_zones = 1;
    map->rpg = rpg;
    map->current_zone_id = 0;
    map->tiles_size = 32;
    my_vec_init(&map->zones, sizeof(zone_t *));
    map->view = sfView_create();
    map->view_pos = (sfVector2f){0, 0};
    map->view_size = (sfVector2f){1920 * SL(rpg), 1080 * SL(rpg)};
    map->current_zoom = 1;
    sfView_setSize(map->view, map->view_size);
    sfView_setCenter(
        map->view, (sfVector2f){map->view_size.x / 2, map->view_size.y / 2});
    sfView_move(map->view, (sfVector2f){-map->view_pos.x, -map->view_pos.y});
    if (map_load_zone(map, ZONE_START, -1, -1) == -1) {
        map_destroy(map);
        return NULL;
    }
    return map;
}
