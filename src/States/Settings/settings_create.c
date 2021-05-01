/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create settings state
*/

#include <stdlib.h>

#include "States/Settings/settings_state.h"

state_t *settings_state_create(game_data_t *data)
{
    settings_state_t *state = malloc(sizeof(*state));

    if (state_init(&state->base, data, SETTINGS_STATE, SETTINGS_DRAW_LAYERS))
        return NULL;
    state->base.vtable = (state_vtable_t){
        .pause = (state_pause_t)&settings_state_pause,
        .resume = (state_resume_t)&settings_state_resume,
        .handle_events = (state_handle_events_t)&settings_state_handle_events,
        .update = (state_update_t)&settings_state_update,
        .draw = (state_draw_t)&settings_state_draw,
        .destroy = (state_destroy_t)&settings_state_destroy,
    };
    return &state->base;
}
