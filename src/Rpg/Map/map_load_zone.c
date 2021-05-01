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

void map_load_zone(map_t *map, int id, int door, int mother)
{
    zone_t *zone = map_get_zone(map, id);

    if (zone)
        map->current_zone = zone;
    else {
        zone = zone_create(map);
        map->current_zone = zone;
        zone_init_from_file(zone, id, door, mother);
        my_vec_push(&map->zones, &zone);
    }
    if (!zone->world)
        return;
    map->rpg->player->body = zone->player_body;
    player_update(map->rpg->player, 1);
    map->rpg->player->body->velocity = VEC2F(0, 0);
    move_view_to_player(map, 1);
    map_reset_zoom(map);
}
