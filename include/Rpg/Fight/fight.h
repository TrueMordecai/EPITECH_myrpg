/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight
*/

#ifndef RPG_FIGHT_H
#define RPG_FIGHT_H

#include <SFML/Graphics.h>
#include "Rpg/Entities/entity.h"
#include "Rpg/Map/physic.h"

struct player_t;

typedef struct cell_t {
    entity_t *entity;
    int physic;
} cell_t;

typedef struct fight_t {
    entity_t **entities;
    int nb_entities;
    cell_t *grid;
    sfVector2i size;
    int turn;
    struct rpg_t *rpg;
} fight_t;

fight_t *fight_create(battle_t *battle, int nb_ennemies, struct player_t *player);
void fight_update(fight_t *fight, float dt);
void fight_destroy(fight_t *fight);

int fight_get_mouse_tile(fight_t *fight);

#endif /* !FIGHT_H_ */