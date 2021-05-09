/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Creates the settings window title
*/

#include <sw/widget.h>

#include "GameEngine/game.h"
#include "States/Settings/settings_state.h"

static void settings_title_update(sw_button_t *title)
{
    sw_base_update(&title->base);
    sw_set_size(
        title, (sw_vec2f_t){SW_SIZE(SW_PARENT(title)).x, SW_SIZE(title).y});
}

sw_widget_t *settings_title_create(settings_state_t *state)
{
    sw_button_t *button = sw_button_create(NULL, NULL);

    button->base.vtable.update = (sw_update_t)&settings_title_update;
    sw_button_set_text(
        button, "Settings", get_font(&state->base.game_data->assets, "pixel2"));
    button->base.data.margin = (sw_spacing_t){.top = 8, .bottom = 8};
    sw_set_size(button, (sw_vec2f_t){0, 35});
    return button;
}
