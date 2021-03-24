/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone init empty
*/

#include "My/my_memory.h"
#include "Rpg/rpg.h"
#include "GameEngine/asset_manager.h"

void zone_init(zone_t *zone, int nb_layers, sfVector2i size)
{
    sfTexture *tex = \
    get_texture(zone->map->rpg->state->game_data->assets, "atlas");

    zone->nb_layers = nb_layers;
    if (nb_layers <= 0)
        return;
    zone->size = size;
    zone->battle = my_calloc(sizeof(int) * size.x * size.y, EMPTY);
    zone->special = my_calloc(sizeof(int) * size.x * size.y, 0);
    zone->layers = my_calloc(sizeof(layer_t **) * nb_layers, 0);
    for (int i = 0; i < nb_layers; i++)
        zone->layers[i] = layer_create(zone->map->view, tex, zone->tiles_size);
    zone->world = pe_world_init(VEC2F(0, 0), \
    MAX(MAX(size.x, size.y), size.x * size.y));
    player_init_physic(zone->map->rpg->player, zone->world);
    physic_add_zone_border(zone);
    physic_add_shaped_tile(zone, (sfVector2i){1, 8}, 12);
    physic_add_shaped_tile(zone, (sfVector2i){1, 10}, 13);
    physic_add_shaped_tile(zone, (sfVector2i){1, 12}, 14);
    physic_add_shaped_tile(zone, (sfVector2i){1, 14}, 15);
}