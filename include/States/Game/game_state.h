/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game state
*/

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "GameEngine/game_head.h"
#include "functions.h"
#include "States/Game/game_cst.h"
#include "Drawables/drawables_head.h"

int game_create(game_data_t *data, state_t *state, size_t datas);
int game_init(state_t *state);
int game_resume(state_t *state, int last_state);
int game_handle_input(state_t *state);
int game_update(state_t *state, float dt);
int game_draw(state_t *state, float dt);
int game_pause(state_t *state, int new_state);
int game_destroy(state_t *state, int from);

#endif /* !MENU_STATE_H */