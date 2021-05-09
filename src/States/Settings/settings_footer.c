/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Creates the settings window footer
*/

#include <stdlib.h>
#include <sw/layouts/grid.h>
#include <sw/widget.h>

#include "GameEngine/game.h"
#include "States/Settings/settings_state.h"

static sw_result_t settings_footer_button_on_event(
    sw_button_t *button, sfEvent const *event)
{
    sw_result_t res = sw_button_on_event(button, event);

    if (sw_button_get_state(button) == SW_BUTTON_HOVERED) {
        if (((settings_footer_t *)SW_PARENT(button))->apply_button == button)
            button->base.data.border_color =
                (sw_color_t){.r = 100, .g = 200, .b = 100, .a = 255};
        else
            button->base.data.border_color =
                (sw_color_t){.r = 200, .g = 100, .b = 100, .a = 255};
    } else {
        button->base.data.border_color =
            (sw_color_t){.r = 150, .g = 150, .b = 150, .a = 255};
    }
    return res;
}

static void settings_footer_button_on_click(
    sw_button_t *button, settings_state_t *state)
{
    if (((settings_footer_t *)SW_PARENT(button))->back_button == button) {
        play_sound(&state->base.game_data->audio, "click");
        game_data_pop_state(state->base.game_data, SETTINGS_STATE);
    } else if (((settings_footer_t *)SW_PARENT(button))->apply_button
        == button) {
        play_sound(&state->base.game_data->audio, "move_zone");
        state->old_settings = state->base.game_data->settings;
        settings_write(&state->base.game_data->settings, SETTINGS_PATH);
    }
}

static sw_button_t *settings_footer_button_create(
    sw_widget_t *parent, settings_state_t *state, char const *text)
{
    sw_button_t *button = sw_button_create(
        parent, (sw_button_on_click_t)&settings_footer_button_on_click);

    sw_button_set_user_data(button, state);
    button->base.vtable.on_event =
        (sw_on_event_t)&settings_footer_button_on_event;
    sw_button_set_text(
        button, text, get_font(&state->base.game_data->assets, "pixel2"));
    button->base.data.border = (sw_spacing_t){.values = {4, 4, 4, 4}};
    button->base.data.margin = (sw_spacing_t){.values = {4, 4, 4, 4}};
    button->base.data.border_color =
        (sw_color_t){.r = 150, .g = 150, .b = 150, .a = 255};
    sw_set_size(button, (sw_vec2f_t){0, 35});
    return button;
}

static void settings_footer_update(settings_footer_t *footer)
{
    sw_widget_t *parent = SW_PARENT(footer);

    if (parent == NULL)
        return;
    sw_set_size(footer, (sw_vec2f_t){SW_SIZE(parent).x, SW_SIZE(footer).y});
    sw_set_size(
        footer->back_button, (sw_vec2f_t){SW_SIZE(footer).x / 2 - 16, 35});
    sw_set_size(
        footer->apply_button, (sw_vec2f_t){SW_SIZE(footer).x / 2 - 16, 35});
    sw_base_update(&footer->base);
}

settings_footer_t *settings_footer_create(settings_state_t *state)
{
    settings_footer_t *footer = malloc(sizeof(*footer));
    sw_glayout_t *layout;

    sw_base_init((sw_base_t *)footer, NULL);
    footer->base.vtable.update = (sw_update_t)&settings_footer_update;
    footer->base.data.margin = (sw_spacing_t){.top = 4, .bottom = 4};
    footer->base.data.border = (sw_spacing_t){.top = 4};
    footer->base.data.padding = (sw_spacing_t){.top = 4, .bottom = 4};
    footer->base.data.border_color =
        (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    layout = sw_glayout_create(footer, (sw_vec2u_t){2, 5});
    footer->back_button = settings_footer_button_create(footer, state, "Back");
    footer->apply_button =
        settings_footer_button_create(footer, state, "Apply");
    sw_glayout_set(layout, footer->back_button, (sw_vec2u_t){0, 0});
    sw_glayout_set(layout, footer->apply_button, (sw_vec2u_t){1, 0});
    settings_refit_size(footer);
    return footer;
}
