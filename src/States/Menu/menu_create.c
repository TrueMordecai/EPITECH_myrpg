/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create menu state
*/

#include <stdlib.h>

#include "States/Menu/menu_state.h"

state_t *menu_state_create(game_data_t *data)
{
    menu_state_t *state = malloc(sizeof(*state));

    if (state_init(&state->base, data, MENU_STATE, MENU_DRAW_LAYERS))
        return NULL;
    state->base.vtable = (state_vtable_t){
        .pause = (state_pause_t)&menu_state_pause,
        .resume = (state_resume_t)&menu_state_resume,
        .handle_events = (state_handle_events_t)&menu_state_handle_events,
        .update = (state_update_t)&menu_state_update,
        .draw = (state_draw_t)&menu_state_draw,
        .destroy = (state_destroy_t)&menu_state_destroy,
    };
    return &state->base;
}
