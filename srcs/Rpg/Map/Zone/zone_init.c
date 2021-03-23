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
    zone->size = size;
    zone->layers = my_calloc(sizeof(layer_t **) * nb_layers, 0);
    for (int i = 0; i < nb_layers; i++) {
        zone->layers[i] = layer_create(zone->map->view, tex, zone->tiles_size);
        layer_init(zone->layers[i], size, 0, (sfVector2i){0, 0});
    }
}