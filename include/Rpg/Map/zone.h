/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** zones
*/

#ifndef ZONE_H
#define ZONE_H

#include <SFML/Graphics.h>
#include "Rpg/Map/battle.h"
#include "Physics/physics.h"

struct map_t;
struct player_t;

typedef struct zone_t {
    int nb_layers;
    int tiles_size;
    sfVector2i size;
    int *special;
    battle_t battle;
    layer_t **layers;
    struct map_t *map;
    pe_world_t *world;
    pe_body_t *player_body;
    char *name;
    int is_battle;
} zone_t;

zone_t *zone_create(struct map_t *map);
void zone_init(zone_t *zone, int nb_layers, sfVector2i size);
int zone_init_from_file(zone_t *zone, char *file);
void zone_sort_layers(zone_t *zone);
void zone_draw(zone_t *zone, sfRenderWindow *wind);
int zone_draw_battle(zone_t *zone, sfRenderWindow *wind, \
sfVector2i min, sfVector2i max);
void zone_draw_layers(zone_t *zone, sfRenderWindow *wind, \
sfVector2i min, sfVector2i max);
void zone_destroy(zone_t *zone);

void zone_add_special(zone_t *zone, sfVector2i pos, int special);

#endif /* !ZONE_H */