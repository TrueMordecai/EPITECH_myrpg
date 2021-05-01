/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The vertical layout
*/

#include <stdint.h>

#include "sw/layouts/vertical.h"
#include "sw/widget.h"

SW_LOCAL void sw_vlayout_drop(sw_vlayout_t *layout)
{
    sw_base_t *owner = layout->base.data.owner;

    if (sw_is_initialized(owner)) {
        sw_vlayout_data_t *widgets = layout->widgets.data;
        size_t count = layout->widgets.length;

        for (size_t i = 0; i < count; ++i)
            sw_set_layout_data(widgets[i].widget, NULL);
    }
    my_vec_free(&layout->widgets, NULL);
}

SW_LOCAL sw_vec2f_t sw_vlayout_get_size(sw_vlayout_t *layout)
{
    sw_vlayout_data_t *widgets = layout->widgets.data;
    size_t widget_count = layout->widgets.length;
    sw_vec2f_t size = {0.0, 0.0};

    for (size_t i = 0; i < widget_count; ++i) {
        sw_vec2f_t wsize;

        if (sw_needs_update(widgets[i].widget))
            sw_update(widgets[i].widget);
        wsize = sw_get_size_spacing(widgets[i].widget);
        size.x += wsize.x;
        if (wsize.y > size.y)
            size.y = wsize.y;
    }
    return size;
}

SW_LOCAL bool sw_vlayout_remove(sw_vlayout_t *layout, sw_base_t *widget)
{
    sw_vlayout_data_t data = *(sw_vlayout_data_t *)sw_get_layout_data(widget);

    my_vec_remove(&layout->widgets, NULL, data.pos);
    for (size_t i = data.pos; i < layout->widgets.length; ++i)
        --((sw_vlayout_data_t *)my_vec_get(&layout->widgets, i))->pos;
    sw_set_layout_data(widget, NULL);
    sw_mark_dirty(widget);
    return true;
}
