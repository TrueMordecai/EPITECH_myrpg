/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Game
*/

#include "States/Game/game_state.h"

int game_state_update(game_state_t *state, float dt)
{
    int was_battle = state->rpg->map->current_zone->is_battle;

    rpg_update(state->rpg, dt);
    game_state_handle_battle_music(
        state, was_battle, state->rpg->map->current_zone->is_battle);
    return 0;
}
