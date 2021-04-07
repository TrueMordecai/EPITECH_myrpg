/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Manages the game state stack
*/

#include <assert.h>

#include "GameEngine/game.h"
#include "GameEngine/state.h"

static int game_data_push_to_states(
    game_data_t *data, state_t *new_state, bool replace)
{
    size_t state_count = data->states.length;

    if (replace)
        game_data_pop_state(data, NULL_STATE);
    if (my_vec_push(&data->states, &new_state)) {
        state_destroy(&new_state, NULL_STATE);
        return 1;
    }
    if (!replace && state_count > 1) {
        state_pause(MY_VEC_GET_ELEM(state_t *, &data->states, state_count - 2),
            new_state->state_id);
    }
    return 0;
}

int game_data_push_state(
    game_data_t *data, state_create_t create_state, bool replace)
{
    state_t *new_state;

    assert(data != NULL);
    assert(create_state != NULL);
    new_state = (*create_state)(data);
    if (new_state == NULL
        || game_data_push_to_states(data, new_state, replace))
        return 1;
    state_resume(new_state, NULL_STATE);
    return 0;
}

void game_data_pop_state(game_data_t *data, state_id_t from)
{
    state_t *top_state;
    state_id_t last_id;

    assert(data != NULL);
    if (data->states.length == 0)
        return;
    my_vec_pop(&data->states, (void *)&top_state);
    last_id = top_state->state_id;
    state_destroy(&top_state, from);
    if (from != NULL_STATE && data->states.length > 0)
        state_resume(
            MY_VEC_GET_ELEM(state_t *, &data->states, data->states.length - 1),
            last_id);
}
