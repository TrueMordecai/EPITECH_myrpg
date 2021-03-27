/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle 
*/

#ifndef RPG_BATTLE_H
#define RPG_BATTLE_H

#include "Rpg/Map/layer.h"

struct zone_t;
struct player_t;

typedef struct battle_t {
    sfVector2i size;
    sfVector2i pos;
    int *tiles;
    layer_t *layer;
    struct zone_t *zone;
    struct player_t *player;
    int tactical;
} battle_t;

void battle_init(battle_t *battle, struct zone_t *zone);
void battle_compute_layer(battle_t *battle);

void battle_start(battle_t *battle);
void battle_end(battle_t *battle);

void battle_set_tactical(battle_t *battle);
void battle_draw_tactical(battle_t *battle, sfRenderWindow *wind, \
sfVector2i min, sfVector2i max);
void battle_draw(battle_t *battle, sfRenderWindow *wind, \
sfVector2i min, sfVector2i max);

#endif /* !RPG_BATTLE_H */