/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** menu state
*/

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameEngine/state.h"

#include "menu_cst.h"

typedef struct menu_state {
    state_t base;
    // This is where you would put data specific to the menu state,
    // such as widgets.
} menu_state_t;

state_t *menu_create(game_data_t *data);
int menu_resume(menu_state_t *state, state_id_t last_state);
int menu_handle_input(menu_state_t *state);
int menu_update(menu_state_t *state, float dt);
int menu_draw(menu_state_t *state, float dt);
int menu_pause(menu_state_t *state, state_id_t new_state);
void menu_destroy(menu_state_t *state, state_id_t from);

#endif /* !MENU_STATE_H */
