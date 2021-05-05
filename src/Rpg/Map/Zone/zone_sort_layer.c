/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone sort layer
*/

#include "Rpg/Map/zone.h"

static int move_layer(layer_t *a, layer_t *b)
{
    int y1 = a->pos.y;
    int y2 = b->pos.y;

    return y1 < y2;
}

void zone_sort_layers(zone_t *zone)
{
    layer_t *layer;
    int j;

    for (int i = 1; i < zone->nb_layers; i++) {
        layer = zone->layers[i];
        j = i - 1;
        while (j >= 0 && move_layer(layer, zone->layers[j])) {
            zone->layers[j + 1] = zone->layers[j];
            j = j - 1;
        }
        zone->layers[j + 1] = layer;
    }
}
