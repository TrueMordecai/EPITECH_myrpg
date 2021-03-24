/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** rpg struct
*/

#ifndef MY_RPG_H
#define MY_RPG_H

#include "GameEngine/game_head.h"
#include "Rpg/Map/map.h"
#include "Rpg/Entities/player.h"
#include "Rpg/Map/physic.h"

#define M_TO_PX 32.f

typedef struct rpg_t {
    state_t *state;
    sfRenderWindow *wind;
    map_t *map;
    player_t *player;
} rpg_t;

rpg_t *rpg_create(state_t *state);
void rpg_handle_input(rpg_t *rpg, sfEvent event);
void rpg_update(rpg_t *rpg, float dt);
void rpg_draw(rpg_t *rpg);
void rpg_destroy(rpg_t *rpg);

#endif /* !MY_RPG_H */