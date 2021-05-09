/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Creates the settings window title
*/

#include <sw/layouts/grid.h>
#include <sw/widget.h>

#include "GameEngine/game.h"
#include "States/Settings/settings_state.h"

static const settings_row_t SETTINGS_ROWS[] = {
    {
        .label = "Music Volume",
        .bounds = {0, 100},
        .value_offset = offsetof(settings_t, music_volume),
    },
    {
        .label = "Sound Volume",
        .bounds = {0, 100},
        .value_offset = offsetof(settings_t, sound_volume),
    },
    {
        .label = "Max FPS",
        .bounds = {15, 300},
        .value_offset = offsetof(settings_t, max_fps),
    },
};

static const size_t SETTINGS_ROW_COUNT =
    sizeof(SETTINGS_ROWS) / sizeof(settings_row_t);

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

static void settings_add_body_rows(
    settings_state_t *state, sw_glayout_t *layout)
{
    game_data_t *data = state->base.game_data;

    for (size_t r = 0; r < SETTINGS_ROW_COUNT; ++r) {
        settings_row_t const *row = &SETTINGS_ROWS[r];
        unsigned *value =
            (unsigned *)(((char *)&SETTINGS(state)) + row->value_offset);

        sw_glayout_set(layout, settings_create_label(data, row->label),
            (sw_vec2u_t){0, r});
        sw_glayout_set(layout,
            settings_adjust_button_create(data, row->bounds, 1, value),
            (sw_vec2u_t){1, r});
        sw_glayout_set(layout, settings_display_button_create(data, value),
            (sw_vec2u_t){2, r});
        sw_glayout_set(layout,
            settings_adjust_button_create(data, row->bounds, -1, value),
            (sw_vec2u_t){3, r});
    }
    sw_layout_update((sw_layout_t *)layout);
}

sw_widget_t *settings_body_create(settings_state_t *state)
{
    sw_widget_t *body = sw_base_create(NULL);
    sw_glayout_t *layout = sw_glayout_create(body, (sw_vec2u_t){4, 3});

    settings_add_body_rows(state, layout);
    settings_refit_size(body);
    return body;
}
