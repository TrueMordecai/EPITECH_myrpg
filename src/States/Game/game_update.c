/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Game
*/

#include "States/Game/game_state.h"

int game_state_update(game_state_t *state, float dt)
{
    rpg_update(state->rpg, dt);
    return 0;
}
