/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** The button that displays the value of a setting
*/

#include <SFML/Window/Keyboard.h>
#include <stdlib.h>
#include <sw/widget.h>

#include "GameEngine/game.h"
#include "functions.h"
#include "States/Settings/settings_state.h"

static void settings_display_button_draw(settings_display_button_t *button,
    sfRenderWindow *window, sw_state_t const *state)
{
    char text[4] = {0};
    unsigned value = *button->value % 1000;

    if (value >= 100) {
        text[0] = '0' + value / 100;
        text[1] = '0' + value / 10 % 10;
        text[2] = '0' + value % 10;
    } else if (value >= 10) {
        text[0] = '0' + value / 10;
        text[1] = '0' + value % 10;
    } else {
        text[0] = '0' + value;
    }
    sw_button_set_text(&button->button, text, NULL);
    sw_button_draw(&button->button, window, state);
}

settings_display_button_t *settings_display_button_create(
    game_data_t *data, unsigned *location)
{
    settings_display_button_t *button = malloc(sizeof(*button));

    if (button == NULL)
        return NULL;
    sw_button_init(&button->button, NULL, NULL);
    button->value = location;
    button->base.vtable.draw = (sw_draw_t)&settings_display_button_draw;
    sw_button_set_text(
        &button->button, "???", get_font(&data->assets, "pixel2"));
    button->base.data.border = (sw_spacing_t){.values = {4, 4, 4, 4}};
    button->base.data.margin = (sw_spacing_t){.values = {4, 4, 4, 4}};
    button->base.data.border_color =
        (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    sw_set_size(button, (sw_vec2f_t){70, 35});
    return button;
}
