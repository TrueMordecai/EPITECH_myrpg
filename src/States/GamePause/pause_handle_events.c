/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** handle game events
*/

#include <SFML/Window/Keyboard.h>

#include "GameEngine/game_head.h"
#include "States/GamePause/pause_state.h"

int pause_state_handle_events(pause_state_t *state)
{
    game_data_t *data = state->base.game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            play_sound(&data->audio, "click");
            game_data_pop_state(state->base.game_data, GAME_STATE);
            return 1;
        }
        if (sw_send_event(state->gui_base, &event) == SW_OK)
            return 1;
    }
    return 0;
}
