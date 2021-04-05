/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create menu state
*/

#include "States/Menu/menu_state.h"

int menu_create(game_data_t *data, state_t *state, size_t datas)
{
    state->init = &menu_init;
    state->resume = &menu_resume;
    state->handle_input = &menu_handle_input;
    state->update = &menu_update;
    state->draw = &menu_draw;
    state->pause = &menu_pause;
    state->destroy = &menu_destroy;
    state->state_id = MENU_STATE;
    state->game_data = data;
    state->state_datas = NULL;
    state->draw_layers = (my_map_t **)my_vector_init(sizeof(my_map_t *), \
    MENU_DRAW_LAYERS);
    for (int i = 0; i < MENU_DRAW_LAYERS; i++)
        my_vector_push((size_t **)&state->draw_layers, \
        (size_t)my_map(unsigned char, draw_elmt_t *, my_map_charcmp, 0, 0));
    return MENU_STATE;
}