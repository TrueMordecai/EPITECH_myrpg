/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** destroy game
*/

#include "States/Game/game_state.h"

void game_destroy(game_state_t *state, state_id_t from)
{
    rpg_destroy(state->rpg);
    (void)from;
}