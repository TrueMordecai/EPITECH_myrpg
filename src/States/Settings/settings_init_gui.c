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
    sw_base_t *box;

    sw_base_init(&state->gui, NULL);
    sw_set_background_texture(&state->gui,
        get_texture(&state->base.game_data->assets, "settings_bg"), 1);
    sw_set_size(&state->gui,
        (sw_vec2f_t){
            SETTINGS(state).window_size.x, SETTINGS(state).window_size.y});
    box = sw_base_create(&state->gui);
    layout = sw_glayout_create(box, (sw_vec2u_t){4, 3});
    box->data.border = (sw_spacing_t){.values = {4, 4, 4, 4}};
    box->data.padding = (sw_spacing_t){.values = {4, 4, 4, 4}};
    box->data.border_color =
        (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    sw_layout_update((sw_layout_t *)layout);
    sw_glayout_set(layout,
        settings_create_label(state->base.game_data, "Music Volume"),
        (sw_vec2u_t){0, 0});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, 1, &SETTINGS(state).music_volume),
        (sw_vec2u_t){1, 0});
    sw_glayout_set(layout,
        settings_display_button_create(
            state->base.game_data, &SETTINGS(state).music_volume),
        (sw_vec2u_t){2, 0});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, -1, &SETTINGS(state).music_volume),
        (sw_vec2u_t){3, 0});
    sw_glayout_set(layout,
        settings_create_label(state->base.game_data, "Sound Volume"),
        (sw_vec2u_t){0, 1});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, 1, &SETTINGS(state).sound_volume),
        (sw_vec2u_t){1, 1});
    sw_glayout_set(layout,
        settings_display_button_create(
            state->base.game_data, &SETTINGS(state).sound_volume),
        (sw_vec2u_t){2, 1});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, -1, &SETTINGS(state).sound_volume),
        (sw_vec2u_t){3, 1});
    sw_glayout_set(layout,
        settings_create_label(state->base.game_data, "Max FPS"),
        (sw_vec2u_t){0, 2});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){15, 300}, 1, &SETTINGS(state).max_fps),
        (sw_vec2u_t){1, 2});
    sw_glayout_set(layout,
        settings_display_button_create(
            state->base.game_data, &SETTINGS(state).max_fps),
        (sw_vec2u_t){2, 2});
    sw_glayout_set(layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){15, 300}, -1, &SETTINGS(state).max_fps),
        (sw_vec2u_t){3, 2});
    sw_set_size(box, (sw_vec2f_t){454, 153});
    sw_set_position(
        box, (sw_vec2f_t){SETTINGS(state).window_size.x / 2 - 227 - 8, 10});
}
