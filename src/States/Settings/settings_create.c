/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create settings state
*/

#include "States/Settings/settings_state.h"

int settings_create(game_data_t *data, state_t *state, size_t datas)
{
    state->init = &settings_init;
    state->resume = &settings_resume;
    state->handle_input = &settings_handle_input;
    state->update = &settings_update;
    state->draw = &settings_draw;
    state->pause = &settings_pause;
    state->destroy = &settings_destroy;
    state->state_id = SETTINGS_STATE;
    state->game_data = data;
    state->state_datas = (size_t *)game_settings_init();
    state->draw_layers = (my_map_t **)my_vector_init(sizeof(my_map_t *), \
    SETTINGS_DRAW_LAYERS);
    for (int i = 0; i < SETTINGS_DRAW_LAYERS; i++)
        my_vector_push((size_t **)&state->draw_layers, \
        (size_t)my_map(unsigned char, draw_elmt_t *, my_map_charcmp, 0, 0));
    return SETTINGS_STATE;
}