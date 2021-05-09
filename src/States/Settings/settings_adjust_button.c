/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** The button that changes the value of a setting
*/

#include <SFML/Window/Keyboard.h>
#include <stdlib.h>
#include <sw/widget.h>

#include "GameEngine/game.h"
#include "GameEngine/settings.h"
#include "functions.h"
#include "States/Settings/settings_state.h"

static void settings_adjust_button_drop(settings_adjust_button_t *button)
{
    sw_button_drop(&button->button);
    button->base_on_event = NULL;
}

static sw_result_t settings_adjust_button_on_event(
    settings_adjust_button_t *button, sfEvent const *event)
{
    sw_result_t res = (*button->base_on_event)(&button->base, event);

    if (sw_button_get_state(&button->button) == SW_BUTTON_HOVERED) {
        button->base.data.border_color =
            (sw_color_t){.r = 200, .g = 100, .b = 100, .a = 255};
    } else {
        button->base.data.border_color =
            (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    }
    return res;
}

static void settings_adjust_button_on_click(
    settings_adjust_button_t *button, unsigned *value)
{
    int result;

    assert(value != NULL);
    if (sfKeyboard_isKeyPressed(sfKeyLControl))
        result = (int)*value + button->offset * 20;
    else if (sfKeyboard_isKeyPressed(sfKeyLShift))
        result = (int)*value + button->offset * 5;
    else
        result = (int)*value + button->offset;
    *value =
        (unsigned)CLAMP(result, (int)button->bounds.x, (int)button->bounds.y);
}

settings_adjust_button_t *settings_adjust_button_create(
    game_data_t *data, sw_vec2u_t bounds, int offset, unsigned *location)
{
    settings_adjust_button_t *button = malloc(sizeof(*button));

    if (button == NULL)
        return NULL;
    sw_button_init(&button->button, NULL,
        (sw_button_on_click_t)&settings_adjust_button_on_click);
    button->base_on_event = button->base.vtable.on_event;
    button->offset = offset;
    sw_button_set_user_data(&button->button, location);
    button->bounds = bounds;
    button->base.vtable.on_event =
        (sw_on_event_t)&settings_adjust_button_on_event;
    button->base.vtable.drop = (sw_drop_t)&settings_adjust_button_drop;
    sw_button_set_text(&button->button, offset < 0 ? "-" : "+",
        get_font(&data->assets, "pixel2"));
    button->base.data.border = (sw_spacing_t){.values = {4, 4, 4, 4}};
    button->base.data.margin = (sw_spacing_t){.values = {4, 4, 4, 4}};
    button->base.data.border_color =
        (sw_color_t){.r = 100, .g = 100, .b = 100, .a = 255};
    sw_set_size(button, (sw_vec2f_t){35, 35});
    return button;
}
