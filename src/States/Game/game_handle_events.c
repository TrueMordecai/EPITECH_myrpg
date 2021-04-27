/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle game events
*/

#include <SFML/Window/Keyboard.h>

#include "States/Game/game_state.h"

state_t *pause_state_create(game_data_t *data);

int game_state_handle_events(game_state_t *state)
{
    game_data_t *data = state->base.game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            game_data_pop_state(state->base.game_data, GAME_STATE);
            return 1;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            game_data_push_state(
                state->base.game_data, &pause_state_create, false);
        rpg_handle_event(state->rpg, event);
    }
    return 0;
}
