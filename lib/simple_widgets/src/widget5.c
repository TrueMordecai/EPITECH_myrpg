/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Universal widget functions, part 5
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "sw/widget.h"

SW_API void *sw_set_layout_data(sw_widget_t *widget, void *data)
{
    void *previous = SW_LAYOUT_DATA(widget);

    ((sw_base_t *)widget)->data.layout_data = data;
    return previous;
}

SW_API bool sw_is_initialized(sw_widget_t *widget)
{
    return widget != NULL
        && ((sw_base_t *)widget)->data.flags & SW_BASE_FLAG_INITIALIZED;
}

SW_API bool sw_needs_update(sw_widget_t *widget)
{
    return ((sw_base_t *)widget)->data.flags & SW_BASE_FLAG_NEEDS_UPDATE;
}

SW_API sw_result_t sw_set_background_texture(
    sw_widget_t *widget, sfTexture const *texture, bool reset_rect)
{
    sw_base_data_t *w = &((sw_base_t *)widget)->data;

    if (reset_rect) {
        sw_vec2u_t t = sfTexture_getSize(texture);

        w->background_size = (sw_vec2i_t){t.x, t.y};
    }
    if (w->background == NULL)
        w->background = sfSprite_create();
    if (w->background == NULL)
        return SW_ERR_ALLOCATION;
    sfSprite_setTexture(w->background, texture, reset_rect);
    return SW_OK;
}

SW_API sw_result_t sw_set_background_texture_rect(
    sw_widget_t *widget, sw_irect_t rect)
{
    sw_base_data_t *w = &((sw_base_t *)widget)->data;

    w->background_size = (sw_vec2i_t){rect.width, rect.height};
    if (w->background == NULL)
        w->background = sfSprite_create();
    if (w->background == NULL)
        return SW_ERR_ALLOCATION;
    sfSprite_setTextureRect(w->background, rect);
    return SW_OK;
}
