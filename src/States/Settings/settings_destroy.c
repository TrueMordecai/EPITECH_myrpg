/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Destroys the settings state
*/

#include <sw/widget.h>

#include "GameEngine/game.h"
#include "States/Settings/settings_state.h"

void settings_state_destroy(settings_state_t *state, state_id_t from)
{
    (void)from;
    sw_drop(&state->gui);
    state->base.game_data->settings = state->old_settings;
    settings_state_update(state, 0);
}
