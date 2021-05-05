/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** handle menu events
*/

#include <SFML/Window/Keyboard.h>

#include "GameEngine/game.h"
#include "States/Game/game_state.h"
#include "States/Menu/menu_state.h"
#include "States/Settings/settings_state.h"

static void shortcuts(game_data_t *data, int key_code)
{
    switch (key_code) {
        case sfKeyEscape: sfRenderWindow_close(data->window); break;
        case sfKeyP:
            play_sound(&data->audio, "click");
            game_data_push_state(data, &game_state_create, false);
            break;
        case sfKeyS:
            play_sound(&data->audio, "click");
            game_data_push_state(data, &settings_state_create, false);
            break;
        default: break;
    }
}

int menu_state_handle_events(menu_state_t *state)
{
    game_data_t *data = state->base.game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed)
            shortcuts(data, event.key.code);
        sw_send_event(state->gui_base, &event);
    }
    return 0;
}
