/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone draw
*/

#include "Rpg/Map/zone.h"

void zone_draw(zone_t *zone, sfRenderWindow *wind)
{
    for (int i = 0; i < zone->nb_layers; i++)
        layer_draw(zone->layers[i], wind);
}