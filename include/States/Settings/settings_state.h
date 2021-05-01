/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** settings state
*/

#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H

#include "GameEngine/state.h"

#include "settings_cst.h"

typedef struct settings_state {
    state_t base;
    // This is where you would put data specific to the settings state.
    // such as widgets.
} settings_state_t;

state_t *settings_state_create(game_data_t *data);
int settings_state_resume(settings_state_t *state, state_id_t last_state);
int settings_state_handle_events(settings_state_t *state);
int settings_state_update(settings_state_t *state, float dt);
int settings_state_draw(settings_state_t *state, float dt);
int settings_state_pause(settings_state_t *state, state_id_t new_state);
void settings_state_destroy(settings_state_t *state, state_id_t from);

#endif /* !SETTINGS_STATE_H */
