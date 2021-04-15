/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Layout System definitions
*/

#include "sw/layout.h"
#include "sw/widget.h"

SW_PROTECTED_API sw_result_t sw_layout_init(
    sw_layout_t *layout, sw_widget_t *owner)
{
    sw_base_t *o = (sw_base_t *)owner;

    if (o == NULL)
        return SW_ERR_NO_OWNER;
    if (o->data.layout != NULL)
        sw_layout_destroy(o->data.layout);
    o->data.layout = layout;
    layout->data.owner = o;
    return SW_OK;
}
