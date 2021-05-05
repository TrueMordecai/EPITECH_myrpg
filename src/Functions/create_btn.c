/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** create_btn
*/

#include <libmy/ascii.h>
#include <sw/widget.h>
#include <sw/widgets/button.h>

#include "functions.h"
#include "GameEngine/game_head.h"

static sw_button_on_click_t get_callback(char *text)
{
    if (my_strcmp(text, "Play") == 0)
        return &cb_menu_play;
    if (my_strcmp(text, "Settings") == 0)
        return &cb_menu_settings;
    if (my_strcmp(text, "Quit") == 0)
        return &cb_menu_quit;
    if (my_strcmp(text, "Resume") == 0)
        return &cb_pause_resume;
    if (my_strcmp(text, "Menu") == 0)
        return &cb_pause_menu;
    return NULL;
}

sw_button_t *create_btn(
    state_t *state, char *text, sw_spacing_t margin, sw_vec2f_t size)
{
    sw_button_t *button = sw_button_create(NULL, get_callback(text));

    sw_button_set_user_data(button, state);
    for (int i = 0; i < 3; i++) {
        sw_button_set_texture(button,
            get_texture(&state->game_data->assets, "buttons"), i, true);
        sw_button_set_texture_rect(
            button, (sw_irect_t){0, i * 80, 195, 80}, i);
    }
    sw_button_set_size(button, size);
    sw_button_set_text(
        button, text, get_font(&state->game_data->assets, "roboto_font"));
    sfText_setFillColor(button->data.text, sfBlack);
    margin.left = (state->game_data->settings->wind_size.x - size.x) / 2.0f;
    button->base.data.margin = margin;
    return button;
}
