/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The grid layout
*/

#include <libmy/core.h>
#include <stdlib.h>

#include "sw/layouts/grid.h"
#include "sw/widget.h"

static void sw_glayout_get_grid_dims(
    sw_glayout_t *layout, float cols_width[], float rows_height[])
{
    size_t count = layout->size.x * layout->size.y;
    sw_glayout_data_t d;
    sw_vec2f_t size;

    for (size_t i = 0; i < count; ++i) {
        d = layout->grid[i];
        if (d.widget == NULL)
            continue;
        if (sw_needs_update(d.widget))
            sw_update(d.widget);
        size = sw_get_size_spacing(d.widget);
        if (size.x > cols_width[d.pos.x])
            cols_width[d.pos.x] = size.x;
        if (size.y > rows_height[d.pos.y])
            rows_height[d.pos.y] = size.y;
    }
}

SW_LOCAL sw_vec2f_t sw_glayout_get_size(sw_glayout_t *layout)
{
    float cols_width[layout->size.x];
    float rows_height[layout->size.y];
    sw_vec2f_t size = {0.0, 0.0};

    for (unsigned i = 0; i < layout->size.x; ++i)
        cols_width[i] = 0.0;
    for (unsigned i = 0; i < layout->size.y; ++i)
        rows_height[i] = 0.0;
    sw_glayout_get_grid_dims(layout, cols_width, rows_height);
    for (unsigned i = 0; i < layout->size.x; ++i)
        size.x += cols_width[i];
    for (unsigned i = 0; i < layout->size.y; ++i)
        size.y += rows_height[i];
    return size;
}

static void sw_glayout_update_row(
    sw_glayout_t *layout, unsigned row, float cols_width[], float row_pos)
{
    sw_vec2f_t pos = {SW_POS(layout->base.data.owner).x, row_pos};

    for (unsigned col = 0; col < layout->size.x; ++col) {
        sw_glayout_data_t d = layout->grid[row * layout->size.x + col];
        float x = pos.x;
        sw_spacing_t m;
        sw_spacing_t b;
        sw_spacing_t p;

        pos.x += cols_width[col];
        if (d.widget == NULL)
            continue;
        m = d.widget->data.margin;
        b = d.widget->data.border;
        p = d.widget->data.padding;
        sw_set_position(d.widget,
            (sw_vec2f_t){
                x + m.left + b.left + p.left, pos.y + m.top + b.top + p.top});
    }
}

SW_LOCAL void sw_glayout_update(sw_glayout_t *layout)
{
    float cols_width[layout->size.x];
    float rows_height[layout->size.y];
    float row_pos = SW_POS(layout->base.data.owner).y;

    for (unsigned i = 0; i < layout->size.x; ++i)
        cols_width[i] = 0.0;
    for (unsigned i = 0; i < layout->size.y; ++i)
        rows_height[i] = 0.0;
    sw_glayout_get_grid_dims(layout, cols_width, rows_height);
    for (unsigned row = 0; row < layout->size.y; ++row) {
        sw_glayout_update_row(layout, row, cols_width, row_pos);
        row_pos += rows_height[row];
    }
}

SW_LOCAL void sw_glayout_drop(sw_glayout_t *layout)
{
    sw_base_t *owner = layout->base.data.owner;

    if (sw_is_initialized(owner)) {
        size_t count = layout->size.x * layout->size.y;

        for (size_t i = 0; i < count; ++i)
            sw_set_layout_data(layout->grid[i].widget, NULL);
    }
    free(layout->grid);
}
