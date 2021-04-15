/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Base widget functions
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

#include "sw/layout.h"
#include "sw/widget.h"

static const sw_base_vtable_t SW_BASE_VTABLE = {
    .set_size = &sw_base_set_size,
    .set_position = &sw_base_set_position,
    .drop = &sw_base_drop,
    .update = &sw_base_update,
    .draw = &sw_base_draw,
};

SW_API sw_result_t sw_base_init(sw_base_t *widget, sw_base_t *parent)
{
    *widget = (sw_base_t){0};
    widget->data.flags = SW_BASE_FLAG_NEEDS_UPDATE | SW_BASE_FLAG_INITIALIZED;
    widget->vtable = SW_BASE_VTABLE;
    my_vec_init(&widget->data.children, sizeof(sw_widget_t *));
    if (parent == NULL)
        return SW_OK;
    sw_set_parent(widget, parent, NULL);
    return SW_OK;
}

SW_API sw_base_t *sw_base_create(sw_base_t *parent)
{
    sw_base_t *widget = malloc(sizeof(*widget));

    if (widget == NULL || sw_base_init(widget, parent) != SW_OK) {
        free(widget);
        return NULL;
    }
    return widget;
}

SW_API void sw_base_drop(sw_base_t *widget)
{
    sw_base_t **children = widget->data.children.data;
    size_t children_count = widget->data.children.length;

    widget->data.flags &= ~SW_BASE_FLAG_INITIALIZED;
    if (widget->data.background != NULL) {
        sfSprite_destroy(widget->data.background);
        widget->data.background = NULL;
    }
    for (size_t i = 0; i < children_count; ++i)
        sw_destroy(children[i]);
    my_vec_free(&widget->data.children, NULL);
    sw_layout_destroy(widget->data.layout);
    sw_remove_child(widget);
}

SW_PROTECTED_API void sw_base_draw(
    sw_base_t *widget, sfRenderWindow *window, sw_state_t const *state)
{
    if (widget->data.background != NULL)
        sfRenderWindow_drawSprite(
            window, widget->data.background, &state->render_states);
    sw_base_draw_border(widget, window, state);
}

SW_PROTECTED_API void sw_base_set_size(sw_base_t *widget, sw_vec2f_t new_size)
{
    widget->data.size = new_size;
    if (widget->data.background != NULL) {
        sw_vec2i_t ssize = widget->data.background_size;
        sw_spacing_t pad = widget->data.padding;
        sw_vec2f_t scale = {
            ssize.x == 0 ? 0 : (pad.left + new_size.x + pad.right) / ssize.x,
            ssize.y == 0 ? 0 : (pad.top + new_size.y + pad.bottom) / ssize.y};

        sfSprite_setScale(widget->data.background, scale);
    }
}
