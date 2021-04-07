/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Creates the game state
*/

#include <assert.h>
#include <stdlib.h>

#include "States/Game/game_state.h"

state_t *game_create(game_data_t *data)
{
    game_state_t *state = malloc(sizeof(*state));

    assert(data != NULL);
    if (state_init(state, GAME_STATE, GAME_DRAW_LAYERS))
        return NULL;
    state->base.vtable = (state_vtable_t){
        .pause = (state_pause_t)&game_pause,
        .resume = (state_resume_t)&game_resume,
        .handle_events = (state_handle_events_t)&game_handle_events,
        .update = (state_update_t)&game_update,
        .draw = (state_draw_t)&game_draw,
        .destroy = (state_destroy_t)&game_destroy,
    };
    state->rpg = rpg_create(state);
    if (state->rpg == NULL) {
        state->base.vtable.destroy = NULL;
        state_destroy(&state, NULL_STATE);
        return NULL;
    }
    return &state->base;
}
