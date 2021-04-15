/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The button widget, part 4
*/

#include "sw/widget.h"
#include "sw/widgets/button.h"

static sw_result_t sw_button_on_mouse_move(
    sw_button_t *widget, bool inside, sfEventType type)
{
    sw_button_state_t state = widget->data.state;

    if (inside && state == SW_BUTTON_IDLE)
        widget->data.state = SW_BUTTON_HOVERED;
    else if (!inside && state != SW_BUTTON_DISABLED)
        widget->data.state = SW_BUTTON_IDLE;
    return inside && type != sfEvtMouseMoved ? SW_OK : SW_PASS;
}

SW_PROTECTED_API sw_result_t sw_button_on_event(
    sw_button_t *widget, sfEvent const *event)
{
    sfEventType t = event->type;
    sw_button_state_t state = widget->data.state;
    bool inside = sw_is_event_inside(widget, event);

    if (t == sfEvtMouseEntered || t == sfEvtMouseLeft || t == sfEvtMouseMoved)
        return sw_button_on_mouse_move(widget, inside, t);
    if (t == sfEvtMouseButtonPressed) {
        if (inside && state != SW_BUTTON_DISABLED)
            widget->data.state = SW_BUTTON_PRESSED;
        return inside ? SW_OK : SW_PASS;
    }
    if (t == sfEvtMouseButtonReleased) {
        if (inside && state == SW_BUTTON_PRESSED) {
            widget->data.state = SW_BUTTON_HOVERED;
            sw_button_click(widget);
        }
        return inside ? SW_OK : SW_PASS;
    }
    return SW_PASS;
}
