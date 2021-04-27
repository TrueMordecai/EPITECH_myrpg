/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game state
*/

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "GameEngine/state.h"
#include "Rpg/rpg.h"

#include "game_cst.h"

typedef struct game_state {
    state_t base;
    rpg_t *rpg;
} game_state_t;

state_t *game_state_create(game_data_t *data);
int game_state_resume(game_state_t *state, state_id_t last_state);
int game_state_handle_events(game_state_t *state);
int game_state_update(game_state_t *state, float dt);
int game_state_draw(game_state_t *state, float dt);
int game_state_pause(game_state_t *state, state_id_t new_state);
void game_state_destroy(game_state_t *state, state_id_t from);

#endif /* !MENU_STATE_H */
