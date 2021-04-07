/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle game events
*/

#include <SFML/Window/Keyboard.h>

#include "States/Game/game_state.h"

int game_handle_events(game_state_t *state)
{
    game_data_t *data = state->base.game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            end_state(state->base.game_data, GAME_STATE);
            return 1;
        }
        rpg_handle_event(state->rpg, event);
    }
    return 0;
}
