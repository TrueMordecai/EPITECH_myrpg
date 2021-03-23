/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** zones
*/

#ifndef ZONE_H
#define ZONE_H

#include <SFML/Graphics.h>

struct map_t;

typedef struct zone_t {
    int nb_layers;
    int tiles_size;
    sfVector2i size;
    int *layers_y;
    sfRectangleShape **tiles;
    struct map_t *map;
} zone_t;

zone_t *zone_create(struct map_t *map);
void zone_destroy(zone_t *zone);

#endif /* !ZONE_H */