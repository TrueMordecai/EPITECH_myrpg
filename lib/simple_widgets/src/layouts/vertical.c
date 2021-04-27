/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The vertical layout
*/

#include <stdlib.h>

#include "sw/layouts/vertical.h"
#include "sw/widget.h"

static const sw_layout_vtable_t SW_VLAYOUT_BASE_VTABLE = {
    .update = (sw_layout_update_t)&sw_vlayout_update,
    .drop = (sw_layout_drop_t)&sw_vlayout_drop,
    .get_size = (sw_layout_get_size_t)&sw_vlayout_get_size,
    .remove = (sw_layout_remove_t)&sw_vlayout_remove,
};

SW_API sw_result_t sw_vlayout_init(sw_vlayout_t *layout, sw_widget_t *owner)
{
    sw_result_t ret = sw_layout_init(&layout->base, owner);

    if (ret != SW_OK)
        return ret;
    my_vec_init(&layout->widgets, sizeof(sw_vlayout_data_t));
    layout->base.vtable = SW_VLAYOUT_BASE_VTABLE;
    return SW_OK;
}

SW_API sw_vlayout_t *sw_vlayout_create(sw_widget_t *owner)
{
    sw_vlayout_t *layout = malloc(sizeof(*layout));

    if (layout == NULL || sw_vlayout_init(layout, owner) != SW_OK) {
        free(layout);
        return NULL;
    }
    return layout;
}

SW_API sw_result_t sw_vlayout_add(sw_vlayout_t *layout, sw_widget_t *widget)
{
    return sw_vlayout_add_multiple(layout, 1, &widget);
}

SW_API sw_result_t sw_vlayout_add_multiple(
    sw_vlayout_t *layout, size_t count, sw_widget_t *widgets[count])
{
    sw_widget_t *owner = layout->base.data.owner;
    sw_list_t *list = &layout->widgets;

    if (my_vec_reserve(&layout->widgets, count) != MY_VEC_OK)
        return SW_ERR_ALLOCATION;
    for (size_t i = 0; i < count; ++i) {
        sw_widget_t *widget = widgets[i];
        sw_vlayout_data_t data = {.widget = widget, .pos = list->length - 1};

        sw_layout_remove(&layout->base, widget);
        my_vec_push(list, &data);
        sw_set_layout_data(widget, my_vec_get(list, data.pos));
        if (SW_PARENT(widget) != owner
            && sw_set_parent(widget, owner, NULL) != SW_OK)
            return SW_ERR_ALLOCATION;
    }
    return SW_OK;
}

SW_LOCAL void sw_vlayout_update(sw_vlayout_t *layout)
{
    sw_vlayout_data_t *widgets = layout->widgets.data;
    size_t widget_count = layout->widgets.length;
    sw_vec2f_t pos = SW_POS(layout->base.data.owner);

    for (size_t i = 0; i < widget_count; ++i) {
        sw_base_t *widget = widgets[i].widget;
        sw_spacing_t m = widget->data.margin;
        sw_spacing_t b = widget->data.border;
        sw_spacing_t p = widget->data.padding;
        float spacing_top = m.top + b.top + p.top;
        float spacing_bottom = m.bottom + b.bottom + p.bottom;

        sw_set_position(widget,
            (sw_vec2f_t){
                pos.x + m.left + b.left + p.left, pos.y + spacing_top});
        pos.y += spacing_top + SW_SIZE(widget).y + spacing_bottom;
    }
}
