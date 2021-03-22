/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** menu state
*/

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "Drawables/drawables_head.h"
#include "GameEngine/game_head.h"
#include "functions.h"
#include "States/Menu/menu_cst.h"

int menu_create(game_data_t *data, state_t *state, size_t datas);
int menu_init(state_t *state);
int menu_resume(state_t *state, int last_state);
int menu_handle_input(state_t *state);
int menu_update(state_t *state, float dt);
int menu_draw(state_t *state, float dt);
int menu_pause(state_t *state, int new_state);
int menu_destroy(state_t *state, int from);

#endif /* !MENU_STATE_H */