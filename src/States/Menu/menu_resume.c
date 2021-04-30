/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Menu - resume
*/

#include <libmy/io/iostream.h>

#include "GameEngine/game_head.h"
#include "States/Menu/menu_state.h"

int menu_state_resume(menu_state_t *state, state_id_t last_state)
{
    my_puts("Menu State\n");
    my_fflush(MY_STDOUT);
    if (last_state == GAME_STATE || last_state == GAME_PAUSE_STATE
        || last_state == NULL_STATE) {
        stop_music(&state->base.game_data->audio);
        play_music(&state->base.game_data->audio, "menu", 1);
    }
    (void)state;
    (void)last_state;
    return 0;
}
