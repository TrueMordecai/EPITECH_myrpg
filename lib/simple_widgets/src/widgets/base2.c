/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Base widget functions
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>

#include "sw/layout.h"
#include "sw/widget.h"

SW_PROTECTED_API void sw_base_set_position(
    sw_base_t *widget, sw_vec2f_t new_pos)
{
    widget->data.pos = new_pos;
    if (widget->data.background != NULL)
        sfSprite_setPosition(widget->data.background, new_pos);
}

static void sw_base_draw_border_rect(sw_base_t *widget, sfRenderWindow *window,
    sw_state_t const *state, sw_vec2f_t dims[8])
{
    sfRectangleShape *rect = sfRectangleShape_create();

    if (rect == NULL)
        return;
    sfRectangleShape_setFillColor(rect, widget->data.border_color.sf_color);
    for (unsigned i = 0; i < 4; ++i) {
        sfRectangleShape_setPosition(rect, dims[i]);
        sfRectangleShape_setSize(rect, dims[i + 4]);
        sfRenderWindow_drawRectangleShape(window, rect, &state->render_states);
    }
    sfRectangleShape_destroy(rect);
}

SW_PROTECTED_API void sw_base_draw_border(
    sw_base_t *widget, sfRenderWindow *window, sw_state_t const *state)
{
    sw_spacing_t pad = widget->data.padding;
    sw_spacing_t b = widget->data.border;
    sw_vec2f_t pos = {SW_POS(widget).x - pad.left, SW_POS(widget).y - pad.top};
    sw_vec2f_t bpos = {pos.x - b.left, pos.y - b.top};
    sw_vec2f_t size = {pad.left + SW_SIZE(widget).x + pad.right,
        pad.top + SW_SIZE(widget).y + pad.bottom};
    sw_vec2f_t bsize = {b.left + size.x + b.right, b.top + size.y + b.bottom};
    sw_vec2f_t dims[8] = {bpos, {bpos.x + b.left + size.x, bpos.y + b.top},
        {bpos.x, bpos.y + b.top + size.y}, {bpos.x, bpos.y + b.top},
        {bsize.x, b.top}, {b.right, size.y}, {bsize.x, b.bottom},
        {b.left, size.y}};

    if (widget->data.border_color.a == 0)
        return;
    sw_base_draw_border_rect(widget, window, state, dims);
}

SW_PROTECTED_API void sw_base_update(sw_base_t *widget)
{
    if (widget->data.layout != NULL)
        sw_layout_update(widget->data.layout);
}
