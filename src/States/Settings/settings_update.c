/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** update Settings
*/

#include "GameEngine/game.h"
#include "GameEngine/audio_manager.h"
#include "States/Settings/settings_state.h"

int settings_state_update(settings_state_t *state, float dt)
{
    audio_manager_update_volume(&state->base.game_data->audio);
    (void)dt;
    return 0;
}
