/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone init empty
*/

#include <libmy/memory/alloc.h>

#include "Rpg/rpg.h"
#include "GameEngine/asset_manager.h"

void zone_init(zone_t *zone, int nb_layers, sfVector2i size)
{
    sfTexture *tex =
        get_texture(&zone->map->rpg->state->game_data->assets, "atlas");

    zone->nb_layers = nb_layers;
    if (nb_layers <= 0)
        return;
    zone->size = size;
    my_vec_init(&zone->sub_doors, sizeof(int));
    my_vec_init(&zone->ext_doors, sizeof(int));
    battle_init(&zone->battle, zone);
    zone->special = my_calloc(size.x * size.y, sizeof(int));
    zone->layers = my_calloc(nb_layers, sizeof(layer_t **));
    for (int i = 0; i < nb_layers; i++)
        zone->layers[i] = layer_create(tex, zone->tiles_size);
    zone->world =
        pe_world_init(VEC2F(0, 0), MAX(MAX(size.x, size.y), size.x * size.y));
    zone->player_body =
        player_init_physic(zone->map->rpg->player, zone->world);
    physic_add_zone_border(zone);
    map_reset_zoom(zone->map);
    map_zoom(zone->map, zone->map->zoom_goal / zone->map->current_zoom);
}

void zone_place_at_door(zone_t *zone, int door)
{
    pe_vec2f_t pos;
    int id;

    if (door < 0 || (size_t)door >= zone->ext_doors.length)
        return;
    id = MY_VEC_GET_ELEM(int, &zone->ext_doors, door);
    pos.x = id % zone->size.x;
    pos.y = id / zone->size.x;
    pe_body_set_pos(zone->player_body, pos);
}
