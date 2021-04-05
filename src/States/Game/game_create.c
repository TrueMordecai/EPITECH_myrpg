/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create game state
*/

#include "States/Game/game_state.h"

int game_create(game_data_t *data, state_t *state, size_t datas)
{
    state->init = &game_init;
    state->resume = &game_resume;
    state->handle_input = &game_handle_input;
    state->update = &game_update;
    state->draw = &game_draw;
    state->pause = &game_pause;
    state->destroy = &game_destroy;
    state->state_id = GAME_STATE;
    state->game_data = data;
    state->state_datas = NULL;
    state->draw_layers = (my_map_t **)my_vector_init(sizeof(my_map_t *), \
    GAME_DRAW_LAYERS);
    for (int i = 0; i < GAME_DRAW_LAYERS; i++)
        my_vector_push((size_t **)&state->draw_layers, \
        (size_t)my_map(unsigned char, draw_elmt_t *, my_map_charcmp, 0, 0));
    return MENU_STATE;
}
