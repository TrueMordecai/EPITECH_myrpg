/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle menu inputs
*/

#include "States/Menu/menu_state.h"

int game_create(game_data_t *data, state_t *state, size_t datas);
int settings_create(game_data_t *data, state_t *state, size_t datas);

static void shortcuts(game_data_t *data, state_t *state, int key_code)
{
    switch (key_code) {
    case sfKeyEscape:
        sfRenderWindow_close(data->window);
        break;
    case sfKeyP:
        add_state(data, &game_create, 0, 0);
        break;
    case sfKeyS:
        add_state(data, &settings_create, 0, 0);
        break;
    default:
        break;
    }
}

int menu_handle_input(state_t *state)
{
    game_data_t *data = state->game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed)
            shortcuts(data, state, event.key.code);
    }
    return 1;
}