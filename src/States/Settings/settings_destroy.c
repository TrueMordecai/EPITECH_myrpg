/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** destroy settings
*/

#include "States/Settings/settings_state.h"

int settings_destroy(state_t *state, int from)
{
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    for (size_t i = 0; i < nb_layers; i++){
        destroy_draw_layer(state->draw_layers[i]);
        my_map_free(&state->draw_layers[i]);
    }
    my_vector_free((size_t **)&state->draw_layers);
    free((void *)state->state_datas);
    free(state);
    return 0;
}