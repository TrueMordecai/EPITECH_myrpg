/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The label widget
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>

#include "sw/widgets/label.h"

static const sw_base_vtable_t SW_LABEL_BASE_VTABLE = {
    .drop = (sw_drop_t)&sw_label_drop,
    .draw = (sw_draw_t)&sw_label_draw,
    .set_position = (sw_set_position_t)&sw_label_set_position,
};

SW_API sw_result_t sw_label_init(
    sw_label_t *widget, sw_widget_t *parent, char const *text, sfFont *font)
{
    sw_result_t ret = sw_base_init(&widget->base, parent);

    if (ret != SW_OK)
        return ret;
    widget->data.text = sfText_create();
    if (widget->data.text == NULL) {
        sw_base_drop(&widget->base);
        return SW_ERR_ALLOCATION;
    }
    sfText_setString(widget->data.text, text);
    sfText_setFont(widget->data.text, font);
    widget->base.vtable = SW_LABEL_BASE_VTABLE;
    return SW_OK;
}

SW_API sw_label_t *sw_label_create(
    sw_widget_t *parent, char const *text, sfFont *font)
{
    sw_label_t *widget = malloc(sizeof(*widget));

    if (widget == NULL || sw_label_init(widget, parent, text, font) != SW_OK) {
        free(widget);
        return NULL;
    }
    return widget;
}

SW_PROTECTED_API void sw_label_drop(sw_label_t *widget)
{
    sw_base_drop(&widget->base);
    if (widget->data.text != NULL) {
        sfText_destroy(widget->data.text);
        widget->data.text = NULL;
    }
}

SW_PROTECTED_API void sw_label_draw(
    sw_label_t *widget, sfRenderWindow *window, sw_state_t const *state)
{
    sw_base_draw(&widget->base, window, state);
    sfRenderWindow_drawText(window, widget->data.text, &state->render_states);
}

SW_PROTECTED_API void sw_label_set_position(
    sw_label_t *widget, sw_vec2f_t new_pos)
{
    sw_base_set_position(&widget->base, new_pos);
    sfText_setPosition(widget->data.text, new_pos);
}
