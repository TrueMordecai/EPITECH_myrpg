/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** btns_callbacks
*/

#include <sw/widgets/button.h>

#include "GameEngine/game_head.h"
#include "States/Game/game_state.h"
#include "States/GamePause/pause_state.h"
#include "States/Menu/menu_state.h"
#include "States/Settings/settings_state.h"

void cb_menu_play(sw_button_t *btn, menu_state_t *state)
{
    play_sound(&state->base.game_data->audio, "click");
    game_data_push_state(state->base.game_data, &game_state_create, false);
    sw_button_set_state(btn, SW_BUTTON_IDLE);
}

void cb_menu_settings(sw_button_t *btn, menu_state_t *state)
{
    play_sound(&state->base.game_data->audio, "click");
    game_data_push_state(state->base.game_data, &settings_state_create, false);
    sw_button_set_state(btn, SW_BUTTON_IDLE);
}

void cb_menu_quit(sw_button_t *btn, menu_state_t *state)
{
    play_sound(&state->base.game_data->audio, "click");
    sfRenderWindow_close(state->base.game_data->window);
    sw_button_set_state(btn, SW_BUTTON_IDLE);
}

void cb_pause_resume(sw_button_t *btn, pause_state_t *state)
{
    play_sound(&state->base.game_data->audio, "click");
    game_data_pop_state(state->base.game_data, GAME_PAUSE_STATE);
    (void)btn;
}

void cb_pause_menu(sw_button_t *btn, pause_state_t *state)
{
    game_data_t *game_data = state->base.game_data;

    (void)btn;
    play_sound(&game_data->audio, "click");
    game_data_pop_state(game_data, GAME_PAUSE_STATE);
    game_data_pop_state(game_data, GAME_PAUSE_STATE);
}
