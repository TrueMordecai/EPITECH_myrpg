/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Intializes the GUI of the settings menu
*/

#include <libmy/ascii/ascii.h>
#include <libmy/printf.h>
#include <sw/layouts/grid.h>
#include <sw/widget.h>

#include "GameEngine/game.h"
#include "GameEngine/settings.h"
#include "States/Settings/settings_state.h"

static sw_widget_t *settings_create_label(game_data_t *data, char const *text)
{
    sw_button_t *button = sw_button_create(NULL, NULL);

    sw_button_set_text(button, text, get_font(&data->assets, "pixel2"));
    button->base.data.border = (sw_spacing_t){.values = {4, 4, 4, 4}};
    button->base.data.margin = (sw_spacing_t){.values = {4, 4, 4, 4}};
    button->base.data.border_color =
        (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    sw_set_size(button, (sw_vec2f_t){250, 35});
    return button;
}

void settings_init_gui(settings_state_t *state)
{
    sw_glayout_t *layout;

    sw_base_init(&state->gui, NULL);
    layout = sw_glayout_create(&state->gui, (sw_vec2u_t){3, 2});
    state->gui.data.border = (sw_spacing_t){.values = {4, 4, 4, 4}};
    state->gui.data.border_color =
        (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    sw_set_size(
        &state->gui, (sw_vec2f_t){1900 * SCL(state), 1060 * SCL(state)});
    sw_set_position(
        &state->gui, (sw_vec2f_t){10 * SCL(state), 10 * SCL(state)});
    sw_layout_update((sw_layout_t *)layout);
    sw_glayout_set(layout,
        settings_create_label(state->base.game_data, "Music Volume"),
        (sw_vec2u_t){0, 0});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, 1,
            &state->base.game_data->settings.music_volume),
        (sw_vec2u_t){1, 0});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, -1,
            &state->base.game_data->settings.music_volume),
        (sw_vec2u_t){2, 0});
    sw_glayout_set(layout,
        settings_create_label(state->base.game_data, "Sound Volume"),
        (sw_vec2u_t){0, 1});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, 1,
            &state->base.game_data->settings.sound_volume),
        (sw_vec2u_t){1, 1});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, -1,
            &state->base.game_data->settings.sound_volume),
        (sw_vec2u_t){2, 1});
}
