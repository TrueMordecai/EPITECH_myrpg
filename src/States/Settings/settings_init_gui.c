/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Intializes the GUI of the settings menu
*/

#include <libmy/ascii/ascii.h>
#include <libmy/printf.h>
#include <sw/layouts/grid.h>
#include <sw/layouts/vertical.h>
#include <sw/widget.h>

#include "GameEngine/game.h"
#include "GameEngine/settings.h"
#include "functions.h"
#include "States/Settings/settings_state.h"

static sw_widget_t *settings_create_title(game_data_t *data, char const *text)
{
    sw_button_t *button = sw_button_create(NULL, NULL);

    sw_button_set_text(button, text, get_font(&data->assets, "pixel2"));
    button->base.data.margin = (sw_spacing_t){.top = 8, .bottom = 8};
    sw_set_size(button, (sw_vec2f_t){0, 35});
    return button;
}

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

static void settings_refit_size(sw_base_t *widget)
{
    sw_vec2f_t max = SW_SIZE(widget);
    size_t children_count;
    sw_widget_t **children = sw_get_children(widget, &children_count);
    sw_widget_t *c;
    sw_vec2f_t bot_left;

    if (children_count == 0)
        sw_update(widget);
    for (size_t i = 0; i < children_count; ++i) {
        c = children[i];
        settings_refit_size(c);
        bot_left = (sw_vec2f_t){SW_POS(c).x + SW_SIZE(c).x + SW_PADDING(c).right
                + SW_BORDER(c).right + SW_MARGIN(c).right,
            SW_POS(c).y + SW_SIZE(c).y + SW_PADDING(c).bottom
                + SW_BORDER(c).bottom + SW_MARGIN(c).bottom};
        max.x = MAX(max.x, bot_left.x);
        max.y = MAX(max.y, bot_left.y);
    }
    sw_set_size(widget, max);
}

void settings_init_gui(settings_state_t *state)
{
    sw_base_t *outer_box;
    sw_base_t *inner_box;
    sw_vlayout_t *outer_layout;
    sw_glayout_t *inner_layout;
    sw_widget_t *title;

    sw_base_init(&state->gui, NULL);
    sw_set_background_texture(&state->gui,
        get_texture(&state->base.game_data->assets, "settings_bg"), 1);
    sw_set_size(&state->gui,
        (sw_vec2f_t){
            SETTINGS(state).window_size.x, SETTINGS(state).window_size.y});
    outer_box = sw_base_create(&state->gui);
    outer_layout = sw_vlayout_create(outer_box);
    title = settings_create_title(state->base.game_data, "Settings");
    sw_vlayout_add(outer_layout, title);
    inner_box = sw_base_create(outer_box);
    sw_vlayout_add(outer_layout, inner_box);
    inner_layout = sw_glayout_create(inner_box, (sw_vec2u_t){4, 3});
    outer_box->data.border = (sw_spacing_t){.values = {4, 4, 4, 4}};
    outer_box->data.padding = (sw_spacing_t){.values = {4, 4, 4, 4}};
    outer_box->data.border_color =
        (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    sw_glayout_set(inner_layout,
        settings_create_label(state->base.game_data, "Music Volume"),
        (sw_vec2u_t){0, 0});
    sw_glayout_set(inner_layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, 1, &SETTINGS(state).music_volume),
        (sw_vec2u_t){1, 0});
    sw_glayout_set(inner_layout,
        settings_display_button_create(
            state->base.game_data, &SETTINGS(state).music_volume),
        (sw_vec2u_t){2, 0});
    sw_glayout_set(inner_layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, -1, &SETTINGS(state).music_volume),
        (sw_vec2u_t){3, 0});
    sw_glayout_set(inner_layout,
        settings_create_label(state->base.game_data, "Sound Volume"),
        (sw_vec2u_t){0, 1});
    sw_glayout_set(inner_layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, 1, &SETTINGS(state).sound_volume),
        (sw_vec2u_t){1, 1});
    sw_glayout_set(inner_layout,
        settings_display_button_create(
            state->base.game_data, &SETTINGS(state).sound_volume),
        (sw_vec2u_t){2, 1});
    sw_glayout_set(inner_layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){0, 100}, -1, &SETTINGS(state).sound_volume),
        (sw_vec2u_t){3, 1});
    sw_glayout_set(inner_layout,
        settings_create_label(state->base.game_data, "Max FPS"),
        (sw_vec2u_t){0, 2});
    sw_glayout_set(inner_layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){15, 300}, 1, &SETTINGS(state).max_fps),
        (sw_vec2u_t){1, 2});
    sw_glayout_set(inner_layout,
        settings_display_button_create(
            state->base.game_data, &SETTINGS(state).max_fps),
        (sw_vec2u_t){2, 2});
    sw_glayout_set(inner_layout,
        settings_adjust_button_create(state->base.game_data,
            (sw_vec2u_t){15, 300}, -1, &SETTINGS(state).max_fps),
        (sw_vec2u_t){3, 2});
    sw_layout_update((sw_layout_t *)outer_layout);
    sw_layout_update((sw_layout_t *)inner_layout);
    settings_refit_size(outer_box);
    sw_set_position(outer_box,
        (sw_vec2f_t){
            (SETTINGS(state).window_size.x - sw_get_size_spacing(outer_box).x)
                    / 2
                - 10,
            SETTINGS(state).window_size.y * 0.1});
    sw_set_size(title, (sw_vec2f_t){SW_SIZE(outer_box).x, SW_SIZE(title).y});
}
