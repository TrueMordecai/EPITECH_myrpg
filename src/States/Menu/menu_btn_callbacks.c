/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** menu_btn_callbacks
*/

#include <libmy/ascii/ascii.h>

#include "States/Menu/menu_state.h"
#include "States/Game/game_state.h"
#include "States/Settings/settings_state.h"

void on_play_click(sw_button_t *btn, void *data)
{
    menu_state_t *state = (menu_state_t *)data;

    game_data_push_state(state->base.game_data, &game_state_create, false);
    sw_button_set_state(btn, SW_BUTTON_IDLE);
}

void on_settings_click(sw_button_t *btn, void *data)
{
    menu_state_t *state = (menu_state_t *)data;

    game_data_push_state(state->base.game_data, &settings_state_create, false);
    sw_button_set_state(btn, SW_BUTTON_IDLE);
}

void on_quit_click(sw_button_t *btn, void *data)
{
    menu_state_t *state = (menu_state_t *)data;

    sfRenderWindow_close(state->base.game_data->window);
    sw_button_set_state(btn, SW_BUTTON_IDLE);
}

sw_button_on_click_t get_callback(char *text)
{
    if (my_strcmp(text, "Play") == 0)
        return &on_play_click;
    if (my_strcmp(text, "Settings") == 0)
        return &on_settings_click;
    if (my_strcmp(text, "Quit") == 0)
        return &on_quit_click;
    return NULL;
}