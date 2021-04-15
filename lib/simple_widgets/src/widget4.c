/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Universal widget functions, part 4
*/

#include <stdint.h>

#include "sw/layout.h"
#include "sw/widget.h"

SW_API sw_layout_t *sw_get_layout(sw_widget_t *widget)
{
    return SW_LAYOUT(widget);
}

SW_API sw_widget_t *sw_get_parent(sw_widget_t *widget)
{
    return SW_PARENT(widget);
}

SW_API sw_result_t sw_set_parent(
    sw_widget_t *widget, sw_widget_t *new_parent, sw_widget_t **old_parent)
{
    sw_list_t *siblings;

    if (old_parent != NULL)
        *old_parent = ((sw_base_t *)widget)->data.parent;
    sw_remove_child(widget);
    if (new_parent == NULL)
        return SW_OK;
    siblings = &((sw_base_t *)new_parent)->data.children;
    if (my_vec_push(siblings, &widget) != MY_VEC_OK) {
        ((sw_base_t *)widget)->data.flags = 0;
        return SW_ERR_ALLOCATION;
    }
    sw_mark_dirty(new_parent);
    sw_mark_dirty(widget);
    ((sw_base_t *)widget)->data.parent = new_parent;
    ((sw_base_t *)widget)->data.child_index = siblings->length - 1;
    return SW_OK;
}

SW_API sw_widget_t *sw_remove_child(sw_widget_t *widget)
{
    sw_base_t *w = (sw_base_t *)widget;
    sw_base_t *parent = SW_PARENT(w);
    sw_base_t **siblings;
    size_t siblings_count;

    if (!sw_is_initialized(parent))
        return NULL;
    sw_layout_remove(SW_LAYOUT(parent), widget);
    sw_mark_dirty(w);
    sw_mark_dirty(parent);
    my_vec_remove(&parent->data.children, NULL, w->data.child_index);
    siblings = parent->data.children.data;
    siblings_count = parent->data.children.length;
    for (size_t i = w->data.child_index; i < siblings_count; ++i)
        --(siblings[i]->data.child_index);
    w->data.child_index = SIZE_MAX;
    w->data.parent = NULL;
    return parent;
}

SW_API void *sw_get_layout_data(sw_widget_t const *widget)
{
    return SW_LAYOUT_DATA(widget);
}
