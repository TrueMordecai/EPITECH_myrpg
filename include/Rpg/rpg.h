/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** rpg struct
*/

#ifndef MY_RPG_H
#define MY_RPG_H

#include "Rpg/Entities/player.h"
#include "Rpg/Map/map.h"
#include "Rpg/Map/physic.h"
#include "GameEngine/game_head.h"
#include "Rpg/Entities/allies.h"

#define M_TO_PX 32.f

typedef struct rpg_t {
    /// key type: 'char *'
    /// Value value: 'spell_base_t *'
    my_hash_map_t spells;
    state_t *state;
    sfRenderWindow *wind;
    map_t *map;
    player_t *player;
    allies_t allies;
} rpg_t;

rpg_t *rpg_create(state_t *state);
void rpg_handle_event(rpg_t *rpg, sfEvent event);
void rpg_update(rpg_t *rpg, float dt);
void rpg_draw(rpg_t *rpg);
void rpg_destroy(rpg_t *rpg);

#endif /* !MY_RPG_H */
