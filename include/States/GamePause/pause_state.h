/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game state
*/

#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include <sw/widget.h>

#include "GameEngine/state.h"

#include "pause_cst.h"

typedef struct pause_state {
    state_t base;
    sw_base_t *gui_base;
} pause_state_t;

state_t *pause_state_create(game_data_t *data);
int pause_state_resume(pause_state_t *state, state_id_t last_state);
int pause_state_handle_events(pause_state_t *state);
int pause_state_update(pause_state_t *state, float dt);
int pause_state_draw(pause_state_t *state, float dt);
int pause_state_pause(pause_state_t *state, state_id_t new_state);
void pause_state_destroy(pause_state_t *state, state_id_t from);

#endif /* !PAUSE_STATE_H */
