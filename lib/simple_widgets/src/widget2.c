/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Universal widget functions, part 2
*/

#include <stdlib.h>
#include "sw/widget.h"
#include "sw/widgets/base.h"

SW_API void sw_draw(
    sw_widget_t *widget, sfRenderWindow *window, sw_state_t const *state)
{
    sw_draw_t draw_func = ((sw_base_t *)widget)->vtable.draw;
    sw_base_t **children = ((sw_base_t *)widget)->data.children.data;
    size_t children_count = ((sw_base_t *)widget)->data.children.length;

    if (sw_needs_update(widget))
        sw_update(widget);
    state = sw_state_get(state);
    if (draw_func != NULL)
        (*draw_func)((sw_base_t *)widget, window, state);
    for (size_t i = 0; i < children_count; ++i)
        sw_draw(children[i], window, state);
}

SW_API sw_result_t sw_send_event(sw_widget_t *widget, sfEvent const *event)
{
    sw_on_event_t on_event_func = ((sw_base_t *)widget)->vtable.on_event;
    sw_result_t ret = SW_PASS;
    sw_base_t **children = ((sw_base_t *)widget)->data.children.data;
    size_t children_count = ((sw_base_t *)widget)->data.children.length;

    if (sw_needs_update(widget))
        sw_update((sw_base_t *)widget);
    if (on_event_func != NULL)
        ret = (*on_event_func)((sw_base_t *)widget, event);
    for (size_t i = 0; ret == SW_PASS && i < children_count; ++i)
        ret = sw_send_event(children[i], event);
    return ret;
}

SW_API void sw_drop(sw_widget_t *widget)
{
    sw_drop_t drop_func;

    if (widget == NULL)
        return;
    drop_func = ((sw_base_t *)widget)->vtable.drop;
    if (drop_func != NULL)
        (*drop_func)((sw_base_t *)widget);
}

SW_API void sw_destroy(sw_widget_t *widget)
{
    sw_drop_t drop_func;

    if (widget == NULL)
        return;
    drop_func = ((sw_base_t *)widget)->vtable.drop;
    if (drop_func != NULL)
        (*drop_func)((sw_base_t *)widget);
    free(widget);
}

SW_API sw_widget_t **sw_get_children(
    sw_widget_t *widget, size_t *children_count)
{
    if (children_count != NULL)
        *children_count = ((sw_base_t *)widget)->data.children.length;
    return ((sw_base_t *)widget)->data.children.data;
}
