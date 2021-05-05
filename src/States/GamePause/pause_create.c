/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Creates the game state
*/

#include <assert.h>
#include <stdlib.h>
#include <sw/layouts/vertical.h>
#include <sw/widgets/button.h>

#include "functions.h"
#include "GameEngine/game_head.h"
#include "States/GamePause/pause_state.h"

void pause_init_gui(pause_state_t *state)
{
    sw_base_t *base = sw_base_create(NULL);
    sw_vlayout_t *layout = sw_vlayout_create(base);

    sw_set_size(base, (sw_vec2f_t){1920 * SCL(state), 1080 * SCL(state)});
    sw_vlayout_update(layout);
    sw_vlayout_add(layout,
        create_btn(&state->base, "Resume",
            (sw_spacing_t){{500 * SCL(state), 0, 75 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    sw_vlayout_add(layout,
        create_btn(&state->base, "Menu",
            (sw_spacing_t){{75 * SCL(state), 0, 75 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    state->gui_base = base;
}

state_t *pause_state_create(game_data_t *data)
{
    pause_state_t *state = malloc(sizeof(*state));

    assert(data != NULL);
    if (state_init(&state->base, data, GAME_STATE, PAUSE_DRAW_LAYERS))
        return NULL;
    state->base.vtable = (state_vtable_t){
        .pause = (state_pause_t)&pause_state_pause,
        .resume = (state_resume_t)&pause_state_resume,
        .handle_events = (state_handle_events_t)&pause_state_handle_events,
        .update = (state_update_t)&pause_state_update,
        .draw = (state_draw_t)&pause_state_draw,
        .destroy = (state_destroy_t)&pause_state_destroy,
    };
    pause_init_gui(state);
    return &state->base;
}
