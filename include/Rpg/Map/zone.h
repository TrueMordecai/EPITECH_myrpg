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

enum ZONE_SPECIAL{SUB_DOOR = 1, EXT_DOOR = 3};
extern const int ZONE_START;
extern const int ZONE_HOUSE;

extern const char *ALL_ZONE_NAMES[5];
extern const sfVector2i *ZONES_LINKS[2];
extern const int *SUB_ZONES_IDS[2];

typedef struct zone_t {
    int nb_layers;
    int tiles_size;
    sfVector2i size;
    int is_battle;
    battle_t battle;
    int *special;
    layer_t **layers;
    struct map_t *map;
    pe_world_t *world;
    pe_body_t *player_body;
    int id;
    int mother_zone;
    int *sub_doors;
    int *ext_doors;
} zone_t;

zone_t *zone_create(struct map_t *map);
void zone_init(zone_t *zone, int nb_layers, sfVector2i size);
void zone_place_at_door(zone_t *zone, int door);
int zone_init_from_file(zone_t *zone, int id, int door, int mother);
void zone_sort_layers(zone_t *zone);
int zone_interract(zone_t *zone);
void zone_draw(zone_t *zone, sfRenderWindow *wind);
int zone_draw_battle(zone_t *zone, sfRenderWindow *wind, \
sfVector2i min, sfVector2i max);
void zone_draw_layers(zone_t *zone, sfRenderWindow *wind, \
sfVector2i min, sfVector2i max);
void zone_destroy(zone_t *zone);

int zone_assert_id(zone_t *zone, int x, int y, int *id);
void zone_add_special(zone_t *zone, sfVector2i pos, int special);

#endif /* !ZONE_H */