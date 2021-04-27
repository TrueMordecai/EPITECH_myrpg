/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Universal widget functions, part 3
*/

#include "sw/widget.h"
#include "sw/widgets/base.h"

SW_API size_t sw_get_children_count(sw_widget_t *widget)
{
    return ((sw_base_t *)widget)->data.children.length;
}

SW_API bool sw_is_inside(sw_widget_t *widget, sw_vec2f_t pos)
{
    sw_vec2f_t p = SW_POS(widget);
    sw_vec2f_t s = SW_SIZE(widget);

    return pos.x >= p.x && pos.x < p.x + s.x && pos.y >= p.y
        && pos.y < p.y + s.y;
}

SW_API bool sw_is_event_inside(sw_widget_t *widget, sfEvent const *event)
{
    switch (event->type) {
        case sfEvtMouseLeft: return false;
        case sfEvtMouseEntered: return true;
        case sfEvtMouseButtonPressed:
        case sfEvtMouseButtonReleased:
            return SW_INSIDE2(
                widget, event->mouseButton.x, event->mouseButton.y);
        case sfEvtMouseMoved:
            return SW_INSIDE2(widget, event->mouseMove.x, event->mouseMove.y);
        case sfEvtMouseWheelMoved:
            return SW_INSIDE2(
                widget, event->mouseWheel.x, event->mouseWheel.y);
        case sfEvtMouseWheelScrolled:
            return SW_INSIDE2(
                widget, event->mouseWheelScroll.x, event->mouseWheelScroll.y);
        default: return false;
    }
}

SW_API void sw_mark_dirty(sw_widget_t *widget)
{
    ((sw_base_t *)widget)->data.flags |= SW_BASE_FLAG_NEEDS_UPDATE;
}

SW_API void sw_update(sw_widget_t *widget)
{
    sw_update_t update_func = ((sw_base_t *)widget)->vtable.update;

    ((sw_base_t *)widget)->data.flags &= ~SW_BASE_FLAG_NEEDS_UPDATE;
    if (update_func != NULL)
        (*update_func)(widget);
}
