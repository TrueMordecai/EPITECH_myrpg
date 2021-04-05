/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle game inputs
*/

#include <math.h>
#include "States/Game/game_state.h"
#include "My/my_convert.h"


int game_handle_input(state_t *state)
{
    game_data_t *data = state->game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed && \
        event.key.code == sfKeyEscape) {
            end_state(state->game_data, GAME_STATE);
            return 1;
        }
        rpg_handle_input((rpg_t *)state->state_datas, event);
    }
    return 1;
}