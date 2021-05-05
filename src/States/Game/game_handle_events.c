/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** handle game events
*/

#include <SFML/Window/Keyboard.h>

#include "States/Game/game_state.h"

state_t *pause_state_create(game_data_t *data);

void game_state_handle_battle_music(
    game_state_t *state, int was_battle, int is_battle)
{
    if (was_battle == is_battle)
        return;
    stop_music(&state->base.game_data->audio);
    if (is_battle)
        play_music(&state->base.game_data->audio, "fight", 1);
    else
        play_music(&state->base.game_data->audio, "game", 1);
}

int game_state_handle_events(game_state_t *state)
{
    game_data_t *data = state->base.game_data;
    sfEvent event;
    int was_battle = state->rpg->map->current_zone->is_battle;

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
    game_state_handle_battle_music(
        state, was_battle, state->rpg->map->current_zone->is_battle);
    return 0;
}
