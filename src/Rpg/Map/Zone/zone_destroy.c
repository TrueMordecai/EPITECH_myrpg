/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone destroy
*/

#include <stdlib.h>
#include "Rpg/Map/zone.h"
#include "Rpg/Fight/fight.h"

void zone_destroy(zone_t *zone)
{
    if (zone->layers) {
        for (int i = 0; i < zone->nb_layers; i++)
            layer_destroy(zone->layers[i]);
        free(zone->layers);
    }
    if (zone->battle.layer)
        layer_destroy(zone->battle.layer);
    if (zone->battle.fight)
        fight_destroy(zone->battle.fight);
    free(zone->battle.tiles);
    free(zone->special);
    my_vec_free(&zone->ext_doors, NULL);
    my_vec_free(&zone->sub_doors, NULL);
    if (zone->world)
        pe_world_destroy(zone->world);
    free(zone);
}
