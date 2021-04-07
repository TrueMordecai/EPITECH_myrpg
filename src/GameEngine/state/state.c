/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** state fcts
*/

#include "GameEngine/game_head.h"

void end_state(game_data_t *data, int from)
{
    state_t *top_state = (state_t *)my_vector_top((size_t *)data->states);
    int last_id;

    if (top_state == NULL)
        return;
    last_id = top_state->state_id;
    top_state->destroy(top_state, from);
    my_vector_pop((size_t **)&data->states);
    top_state = (state_t *)my_vector_top((size_t *)data->states);
    if (top_state != NULL && from != NULL_STATE)
        top_state->resume(top_state, last_id);
}

void game_push_state(game_data_t *data, int (*state_create)(game_data_t *, \
state_t *, size_t), int replace, size_t datas)
{
    size_t nb_states = my_vector_get_size((size_t *)data->states);
    state_t *new_state = malloc(sizeof(state_t));
    int new_id;

    new_id = state_create(data, new_state, datas);
    if (replace)
        end_state(data, NULL_STATE);
    if (!replace && nb_states > 0) {
        data->states[nb_states - 1]->pause(data->states[nb_states - 1], new_id);
    }
    new_state->init(new_state);
    new_state->resume(new_state, NULL_STATE);
    my_vector_push((size_t **)&data->states, (size_t)new_state);
}
