/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** MyRPG struct
*/

#ifndef MY_RPG_H
#define MY_RPG_H

#include "Rpg/Entities/allies.h"
#include "Rpg/Entities/player.h"
#include "Rpg/Interfarces/inventory.h"
#include "Rpg/Map/map.h"
#include "Rpg/Map/physic.h"
#include "GameEngine/game_head.h"
#include "Quests/quests.h"

#define M_TO_PX 32.f

typedef struct rpg_t {
    /// key type: 'char *'
    /// Value value: 'spell_base_t *'
    my_hash_map_t spells;
    state_t *state;
    sfRenderWindow *wind;
    map_t *map;
    player_t *player;
    inventory_t inventory;
    allies_t allies;
    quest_list_t quests;
} rpg_t;

rpg_t *rpg_create(state_t *state);
void rpg_handle_event(rpg_t *rpg, sfEvent event);
void rpg_update(rpg_t *rpg, float dt);
void rpg_draw(rpg_t *rpg);
void rpg_destroy(rpg_t *rpg);

#endif /* !MY_RPG_H */
