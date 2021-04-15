/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The button widget
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>

#include "sw/widgets/button.h"

static const sw_base_vtable_t SW_BUTTON_BASE_VTABLE = {
    .drop = (sw_drop_t)&sw_button_drop,
    .draw = (sw_draw_t)&sw_button_draw,
    .set_position = (sw_set_position_t)&sw_button_set_position,
    .set_size = (sw_set_size_t)&sw_button_set_size,
    .on_event = (sw_on_event_t)&sw_button_on_event,
};

SW_API sw_result_t sw_button_init(
    sw_button_t *widget, sw_widget_t *parent, sw_button_on_click_t on_click)
{
    sw_result_t ret = sw_base_init(&widget->base, parent);
    sfText *text;

    if (ret != SW_OK)
        return ret;
    text = sfText_create();
    if (text == NULL) {
        sw_button_drop(widget);
        return SW_ERR_ALLOCATION;
    }
    widget->data = (sw_button_data_t){
        .state = SW_BUTTON_IDLE,
        .on_click = on_click,
        .has_text = false,
        .text = text,
    };
    widget->base.vtable = SW_BUTTON_BASE_VTABLE;
    return SW_OK;
}

SW_API sw_button_t *sw_button_create(
    sw_widget_t *parent, sw_button_on_click_t on_click)
{
    sw_button_t *widget = malloc(sizeof(*widget));

    if (widget == NULL || sw_button_init(widget, parent, on_click) != SW_OK) {
        free(widget);
        return NULL;
    }
    return widget;
}

SW_API void sw_button_set_text(
    sw_button_t *widget, char const *text, sfFont *font)
{
    sfFloatRect text_rect;

    if (text != NULL) {
        sfText_setString(widget->data.text, text);
        widget->data.has_text = *text != '\0';
    }
    if (font != NULL)
        sfText_setFont(widget->data.text, font);
    text_rect = sfText_getLocalBounds(widget->data.text);
    sfText_setOrigin(widget->data.text,
        (sw_vec2f_t){text_rect.left + text_rect.width / 2,
            text_rect.top + text_rect.height / 2});
}

SW_API void sw_button_click(sw_button_t *widget)
{
    sw_button_on_click_t click_func = widget->data.on_click;

    if (click_func != NULL)
        (*click_func)(widget, widget->data.user_data);
}

SW_API sw_button_state_t sw_button_get_state(sw_button_t const *widget)
{
    return widget->data.state;
}
