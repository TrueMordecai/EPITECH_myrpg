/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** destroy game
*/

#include "States/GamePause/pause_state.h"

void pause_state_destroy(pause_state_t *state, state_id_t from)
{
    sw_destroy(state->gui_base);
    (void)from;
}
