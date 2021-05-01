/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** SW State definitions
*/

#include "sw/state.h"

SW_API sw_state_t *sw_state_init(
    sw_state_t *state, sfRenderStates const *render_states)
{
    if (state == NULL)
        return NULL;
    if (render_states != NULL) {
        state->render_states = *render_states;
    } else {
        state->render_states = (sfRenderStates){
            .blendMode = sfBlendAlpha, .transform = sfTransform_Identity};
    }
    return state;
}

SW_API sw_state_t const *sw_state_get(sw_state_t const *state)
{
    static sw_state_t default_state;

    if (default_state.render_states.blendMode.colorDstFactor == 0) {
        default_state = (sw_state_t){
            .render_states =
                {
                    .blendMode = sfBlendAlpha,
                    .transform = sfTransform_Identity,
                },
        };
    }
    return state == NULL ? &default_state : state;
}
