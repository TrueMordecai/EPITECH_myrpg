/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Creates the game state
*/

#include <assert.h>
#include <stdlib.h>

#include "States/Game/game_state.h"

state_t *game_state_create(game_data_t *data)
{
    game_state_t *state = malloc(sizeof(*state));

    assert(data != NULL);
    if (state_init(&state->base, data, GAME_STATE, GAME_DRAW_LAYERS))
        return NULL;
    state->base.vtable = (state_vtable_t){
        .pause = (state_pause_t)&game_state_pause,
        .resume = (state_resume_t)&game_state_resume,
        .handle_events = (state_handle_events_t)&game_state_handle_events,
        .update = (state_update_t)&game_state_update,
        .draw = (state_draw_t)&game_state_draw,
        .destroy = (state_destroy_t)&game_state_destroy,
    };
    state->rpg = rpg_create(&state->base);
    if (state->rpg == NULL) {
        state->base.vtable.destroy = NULL;
        state_destroy((state_t **)&state, NULL_STATE);
        return NULL;
    }
    return &state->base;
}
