/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone interract
*/

#include "Rpg/rpg.h"

int zone_assert_id(zone_t *zone, int x, int y, int *id)
{
    if (x < 0 || x >= zone->size.x || y < 0 || y >= zone->size.y)
        return 0;
    if (id)
        *id = x + y * zone->size.x;
    return 1;
}

static sfVector2i get_interract_pos(
    zone_t *zone, sfVector2i dir, sfVector2i start)
{
    int id;
    sfVector2i lat_dir = {(dir.x) ? 0 : 1, (dir.y) ? 0 : 1};

    if (!zone->world)
        return (sfVector2i){-1, -1};
    if (zone->special[start.x + start.y * zone->size.x])
        return start;
    if (zone_assert_id(zone, start.x + dir.x, start.y + dir.y, &id)
        && zone->special[id])
        return (sfVector2i){start.x + dir.x, start.y + dir.y};
    if (zone_assert_id(zone, start.x + lat_dir.x, start.y + lat_dir.y, &id)
        && zone->special[id])
        return (sfVector2i){start.x + lat_dir.x, start.y + lat_dir.y};
    if (zone_assert_id(zone, start.x - lat_dir.x, start.y - lat_dir.y, &id)
        && zone->special[id])
        return (sfVector2i){start.x - lat_dir.x, start.y - lat_dir.y};
    return (sfVector2i){-1, -1};
}

static int get_doors_id(zone_t *zone, int pos_id, int doors)
{
    my_vec_t *d_vec = doors == SUB_DOOR ? &zone->sub_doors : &zone->ext_doors;
    size_t nb_doors = d_vec->length;
    int id;

    for (size_t i = 0; i < nb_doors; i++) {
        id = MY_VEC_GET_ELEM(int, d_vec, i);
        if (pos_id == id)
            return i;
    }
    return -1;
}

static void handle_doors(zone_t *zone, sfVector2i pos, int pos_id, int doors)
{
    int door_id = get_doors_id(zone, pos_id, doors);
    int zone_id = 0;
    int open_door = -1;
    int mother = -1;

    if (door_id == -1 || (doors != SUB_DOOR && doors != EXT_DOOR))
        return;
    if (doors == SUB_DOOR) {
        zone_id = SUB_ZONES_IDS[zone->id][door_id];
        mother = zone->id;
        open_door = 0;
    } else {
        if (zone->mother_zone < 0) {
            zone_id = ZONES_LINKS[zone->id][door_id].x;
            open_door = ZONES_LINKS[zone->id][door_id].y;
        } else
            zone_id = zone->mother_zone;
    }
    (void)pos;
    (void)doors;
    map_load_zone(zone->map, zone_id, open_door, mother);
}

int zone_interract(zone_t *zone)
{
    player_t *player = zone->map->rpg->player;
    sfVector2i dir = player->dir;
    sfVector2i pos = {zone->player_body->pos.x, zone->player_body->pos.y};
    sfVector2i it_pos = get_interract_pos(zone, dir, pos);
    int special;

    if (it_pos.x == -1 && it_pos.y == -1)
        return 0;
    special = zone->special[it_pos.x + it_pos.y * zone->size.x];
    handle_doors(zone, it_pos, it_pos.x + it_pos.y * zone->size.x, special);
    return 1;
}
