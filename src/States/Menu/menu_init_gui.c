/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** menu_init_gui
*/

#include <libmy/ascii/ascii.h>
#include <libmy/printf.h>

#include "GameEngine/game_head.h"
#include "States/Game/game_state.h"
#include "States/Menu/menu_state.h"
#include "States/Settings/settings_state.h"

sw_button_on_click_t get_callback(char *text);

static sw_button_t *create_btn(
    menu_state_t *state, char *text, sw_spacing_t margin, sw_vec2f_t size)
{
    sw_button_t *button = sw_button_create(NULL, get_callback(text));

    sw_button_set_user_data(button, state);
    for (int i = 0; i < 3; i++) {
        sw_button_set_texture(button,
            get_texture(&state->base.game_data->assets, "buttons"), i, true);
        sw_button_set_texture_rect(
            button, (sw_irect_t){0, i * 80, 195, 80}, i);
    }
    sw_button_set_size(button, size);
    sw_button_set_text(
        button, text, get_font(&state->base.game_data->assets, "roboto_font"));
    sfText_setFillColor(button->data.text, sfBlack);
    margin.left =
        (state->base.game_data->settings->wind_size.x - size.x) / 2.0f;
    button->base.data.margin = margin;
    return button;
}

void menu_init_gui(menu_state_t *state)
{
    sw_base_t *base = sw_base_create(NULL);
    sw_vlayout_t *layout = sw_vlayout_create(base);

    sw_set_size(base, (sw_vec2f_t){1920 * SCL(state), 1080 * SCL(state)});
    sw_vlayout_update(layout);
    sw_vlayout_add(layout,
        create_btn(state, "Play",
            (sw_spacing_t){{400 * SCL(state), 0, 75 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    sw_vlayout_add(layout,
        create_btn(state, "Settings",
            (sw_spacing_t){{75 * SCL(state), 0, 75 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    sw_vlayout_add(layout,
        create_btn(state, "Quit", (sw_spacing_t){{75 * SCL(state), 0, 0, 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    state->gui_base = base;
}