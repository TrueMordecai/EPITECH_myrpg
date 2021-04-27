/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Layout System definitions
*/

#include <stdlib.h>

#include "sw/layout.h"
#include "sw/widget.h"

SW_API void sw_layout_destroy(sw_layout_t *layout)
{
    sw_layout_drop_t drop_func;

    if (layout == NULL)
        return;
    drop_func = layout->vtable.drop;
    if (drop_func != NULL)
        (*drop_func)(layout);
    free(layout);
}

SW_API void sw_layout_update(sw_layout_t *layout)
{
    sw_layout_update_t update_func = layout->vtable.update;

    if (update_func != NULL)
        (*update_func)(layout);
}

SW_API sw_vec2f_t sw_layout_get_size(sw_layout_t *layout)
{
    sw_layout_get_size_t get_size_func = layout->vtable.get_size;

    if (get_size_func != NULL)
        return (*get_size_func)(layout);
    return (sw_vec2f_t){0.0, 0.0};
}

SW_API bool sw_layout_contains(sw_layout_t *layout, sw_widget_t const *widget)
{
    sw_base_t *parent;

    if (layout == NULL || widget == NULL || sw_get_layout_data(widget) == NULL)
        return false;
    parent = SW_PARENT(widget);
    return parent != NULL && SW_LAYOUT(parent) == layout;
}

SW_API bool sw_layout_remove(sw_layout_t *layout, sw_widget_t *widget)
{
    sw_layout_remove_t remove_func;

    if (!sw_layout_contains(layout, widget))
        return false;
    remove_func = layout->vtable.remove;
    return remove_func != NULL && (*remove_func)(layout, widget);
}
