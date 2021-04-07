/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle menu events
*/

#include <SFML/Window/Keyboard.h>

#include "GameEngine/game.h"
#include "States/Game/game_state.h"
#include "States/Menu/menu_state.h"
#include "States/Settings/settings_state.h"

static void shortcuts(game_data_t *data, state_t *state, int key_code)
{
    switch (key_code) {
        case sfKeyEscape: sfRenderWindow_close(data->window); break;
        case sfKeyP: game_push_state(data, &game_create, 0, 0); break;
        case sfKeyS: game_push_state(data, &settings_create, 0, 0); break;
        default: break;
    }
}

int menu_handle_events(menu_state_t *state)
{
    game_data_t *data = state->base.game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed)
            shortcuts(data, state, event.key.code);
    }
    return 0;
}
