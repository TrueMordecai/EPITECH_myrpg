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

state_t *game_create(game_data_t *data);
int game_resume(state_t *state, state_id_t last_state);
int game_handle_input(state_t *state);
int game_update(state_t *state, float dt);
int game_draw(state_t *state, float dt);
int game_pause(state_t *state, state_id_t new_state);
void game_destroy(state_t *state, state_id_t from);

#endif /* !MENU_STATE_H */
