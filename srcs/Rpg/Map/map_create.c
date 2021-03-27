/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map create
*/

#include "My/my_memory.h"
#include "Rpg/rpg.h"

map_t *map_create(rpg_t *rpg)
{
    map_t *map = my_calloc(sizeof(map_t), 0);

    map->nb_zones = 1;
    map->rpg = rpg;
    map->current_zone_id = 0;
    map->tiles_size = 32;
    map->zones = (zone_t **)my_vector_init(sizeof(zone_t *), 2);
    map->view = sfView_create();
    map->view_pos = (sfVector2f){0, 0};
    map->view_size = (sfVector2f){1920 * SL(rpg), 1080 * SL(rpg)};
    map->current_zoom = 1;
    sfView_setSize(map->view, map->view_size);
    sfView_setCenter(map->view, (sfVector2f){map->view_size.x / 2, \
        map->view_size.y / 2});
    sfView_move(map->view, (sfVector2f){-map->view_pos.x, -map->view_pos.y});
    map_load_zone(map, "assets/Zones/zone_test");
    return map;
}