/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Universal widget functions
*/

#include "sw/widget.h"
#include "sw/widgets/base.h"

SW_API sw_vec2f_t sw_get_size(sw_widget_t *widget)
{
    return ((sw_base_t *)widget)->data.pos;
}

SW_API sw_vec2f_t sw_get_size_spacing(sw_widget_t *widget)
{
    sw_spacing_t m = SW_MARGIN(widget);
    sw_spacing_t b = SW_BORDER(widget);
    sw_spacing_t p = SW_PADDING(widget);
    sw_vec2f_t s = SW_SIZE(widget);

    return (sw_vec2f_t){
        m.left + b.left + p.left + s.x + p.right + b.right + m.right,
        m.top + b.top + p.top + s.y + p.bottom + b.bottom + m.bottom};
}

SW_API sw_vec2f_t sw_set_size(sw_widget_t *widget, sw_vec2f_t new_size)
{
    sw_vec2f_t old_size = ((sw_base_t *)widget)->data.pos;
    sw_set_size_t resize_func = ((sw_base_t *)widget)->vtable.set_size;

    if (resize_func != NULL)
        (*resize_func)((sw_base_t *)widget, new_size);
    return old_size;
}

SW_API sw_vec2f_t sw_get_position(sw_widget_t *widget)
{
    return ((sw_base_t *)widget)->data.pos;
}

SW_API sw_vec2f_t sw_set_position(sw_widget_t *widget, sw_vec2f_t pos)
{
    sw_vec2f_t old_pos = ((sw_base_t *)widget)->data.pos;
    sw_set_position_t move_func = ((sw_base_t *)widget)->vtable.set_position;
    size_t children_count;
    sw_base_t **children;
    sw_vec2f_t offset;

    if (move_func == NULL)
        return old_pos;
    (*move_func)((sw_base_t *)widget, pos);
    children_count = ((sw_base_t *)widget)->data.children.length;
    children = ((sw_base_t *)widget)->data.children.data;
    offset = (sw_vec2f_t){pos.x - old_pos.x, pos.y - old_pos.y};
    for (size_t i = 0; i < children_count; ++i) {
        sw_vec2f_t child_pos = children[i]->data.pos;

        sw_set_position(children[i],
            (sw_vec2f_t){child_pos.x + offset.x, child_pos.y + offset.y});
    }
    return old_pos;
}
