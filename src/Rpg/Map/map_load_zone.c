/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map load zone
*/

#include "Rpg/rpg.h"

zone_t *map_get_zone(map_t *map, int id)
{
    size_t zone_count = map->zones.length;

    for (size_t i = 0; i < zone_count; i++) {
        zone_t *zone = MY_VEC_GET_ELEM(zone_t *, &map->zones, i);

        if (id == zone->id)
            return zone;
    }
    return NULL;
}

static zone_t *try_load_zone(map_t *map, int id, int door, int mother)
{
    zone_t *cur_zone = map->current_zone;
    zone_t *zone = map_get_zone(map, id);

    if (zone) {
        map->current_zone = zone;
        return zone;
    }
    zone = zone_create(map);
    map->current_zone = zone;
    if (zone_init_from_file(zone, id, door, mother)) {
        zone_destroy(zone);
        map->current_zone = cur_zone;
        return NULL;
    }
    my_vec_push(&map->zones, &zone);
    return zone;
}

int map_load_zone(map_t *map, int id, int door, int mother)
{
    zone_t *zone = try_load_zone(map, id, door, mother);

    if (!zone || !zone->world)
        return -1;
    map->current_zone = zone;
    map->rpg->player->body = zone->player_body;
    player_update(map->rpg->player, 1);
    map->rpg->player->body->velocity = VEC2F(0, 0);
    move_view_to_player(map, 1);
    map_reset_zoom(map);
    zone_place_at_door(zone, door);
    return 0;
}
