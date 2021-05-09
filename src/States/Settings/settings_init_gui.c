/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Intializes the GUI of the settings menu
*/

#include <sw/layouts/vertical.h>
#include <sw/widget.h>

#include "GameEngine/game.h"
#include "functions.h"
#include "States/Settings/settings_state.h"

void settings_refit_size(sw_widget_t *widget)
{
    sw_vec2f_t max = SW_SIZE(widget);
    size_t children_count;
    sw_widget_t **children = sw_get_children(widget, &children_count);
    sw_widget_t *c;
    sw_vec2f_t bot_left;

    sw_update(widget);
    for (size_t i = 0; i < children_count; ++i) {
        c = children[i];
        bot_left = (sw_vec2f_t){SW_POS(c).x + SW_SIZE(c).x + SW_PADDING(c).right
                + SW_BORDER(c).right + SW_MARGIN(c).right,
            SW_POS(c).y + SW_SIZE(c).y + SW_PADDING(c).bottom
                + SW_BORDER(c).bottom + SW_MARGIN(c).bottom};
        max.x = MAX(max.x, bot_left.x);
        max.y = MAX(max.y, bot_left.y);
    }
    sw_set_size(widget, max);
}

static sw_base_t *settings_window_create(
    sw_widget_t *parent, sw_vlayout_t **window_layout)
{
    sw_base_t *window = sw_base_create(parent);

    *window_layout = sw_vlayout_create(window);
    window->data.border = (sw_spacing_t){.values = {4, 4, 4, 4}};
    window->data.padding = (sw_spacing_t){.values = {4, 4, 4, 4}};
    window->data.border_color =
        (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    return window;
}

static void settings_add_window(settings_state_t *state)
{
    sw_vlayout_t *window_layout;
    sw_base_t *window = settings_window_create(&state->gui, &window_layout);
    sw_widget_t *title = settings_title_create(state);
    sw_widget_t *footer = settings_footer_create(state);

    sw_vlayout_add(window_layout, title);
    sw_vlayout_add(window_layout, settings_body_create(state));
    sw_vlayout_add(window_layout, footer);
    sw_layout_update((sw_layout_t *)window_layout);
    settings_refit_size(window);
    sw_set_position(window,
        (sw_vec2f_t){
            (WINDOW_SIZE(state).x - sw_get_size_spacing(window).x) / 2 - 10,
            (WINDOW_SIZE(state).y - sw_get_size_spacing(window).y) / 2});
    sw_update(title);
    sw_update(footer);
    sw_layout_update((sw_layout_t *)window_layout);
}

void settings_init_gui(settings_state_t *state)
{
    sw_base_init(&state->gui, NULL);
    sw_set_background_texture(&state->gui,
        get_texture(&state->base.game_data->assets, "settings_bg"), 1);
    sw_set_size(
        &state->gui, (sw_vec2f_t){WINDOW_SIZE(state).x, WINDOW_SIZE(state).y});
    settings_add_window(state);
}
