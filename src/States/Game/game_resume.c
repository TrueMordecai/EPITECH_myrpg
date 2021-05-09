/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Menu - resume
*/

#include <libmy/io/iostream.h>

#include "States/Game/game_state.h"

int game_state_resume(game_state_t *state, state_id_t last_state)
{
    my_fflush(MY_STDOUT);
    if (last_state == MENU_STATE || last_state == NULL_STATE) {
        stop_music(&state->base.game_data->audio);
        play_music(&state->base.game_data->audio, "game", 1);
    }
    return 0;
}
