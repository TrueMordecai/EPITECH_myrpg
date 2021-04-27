/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The grid layout
*/

#include <libmy/core.h>
#include <limits.h>
#include <stdlib.h>

#include "sw/layouts/grid.h"
#include "sw/widget.h"

static const sw_layout_vtable_t SW_GLAYOUT_BASE_VTABLE = {
    .update = (sw_layout_update_t)&sw_glayout_update,
    .drop = (sw_layout_drop_t)&sw_glayout_drop,
    .get_size = (sw_layout_get_size_t)&sw_glayout_get_size,
    .remove = (sw_layout_remove_t)&sw_glayout_remove,
};

SW_API sw_result_t sw_glayout_init(
    sw_glayout_t *layout, sw_widget_t *owner, sw_vec2u_t size)
{
    sw_result_t ret = sw_layout_init(&layout->base, owner);
    size_t count = size.x * size.y;

    if (ret != SW_OK)
        return ret;
    layout->grid = malloc(sizeof(*layout->grid) * count);
    if (layout->grid == NULL)
        return SW_ERR_ALLOCATION;
    for (size_t i = 0; i < count; ++i)
        layout->grid[i] =
            (sw_glayout_data_t){.widget = NULL, .pos = {UINT_MAX, UINT_MAX}};
    layout->base.vtable = SW_GLAYOUT_BASE_VTABLE;
    layout->size = size;
    return SW_OK;
}

SW_API sw_glayout_t *sw_glayout_create(sw_widget_t *owner, sw_vec2u_t size)
{
    sw_glayout_t *layout = malloc(sizeof(*layout));

    if (layout == NULL || sw_glayout_init(layout, owner, size) != SW_OK) {
        free(layout);
        return NULL;
    }
    return layout;
}

SW_API sw_result_t sw_glayout_set(
    sw_glayout_t *layout, sw_widget_t *widget, sw_vec2u_t pos)
{
    sw_widget_t *owner = layout->base.data.owner;
    sw_vec2u_t size = layout->size;
    sw_glayout_data_t *data;

    if (pos.x >= size.x || pos.y >= size.y)
        return SW_ERR_OUT_OF_BOUNDS;
    if (SW_PARENT(widget) != owner
        && sw_set_parent(widget, owner, NULL) != SW_OK)
        return SW_ERR_ALLOCATION;
    sw_layout_remove(&layout->base, widget);
    data = &layout->grid[pos.y * size.x + pos.x];
    data->widget = widget;
    data->pos = pos;
    sw_set_layout_data(widget, data);
    return SW_OK;
}

SW_LOCAL bool sw_glayout_remove(sw_glayout_t *layout, sw_base_t *widget)
{
    sw_glayout_data_t *data = sw_get_layout_data(widget);

    data->widget = NULL;
    data->pos = (sw_vec2u_t){UINT_MAX, UINT_MAX};
    sw_set_layout_data(widget, NULL);
    sw_mark_dirty(widget);
    (void)layout;
    return true;
}
