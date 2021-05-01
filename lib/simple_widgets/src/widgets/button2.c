/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The button widget, part 2
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "sw/widgets/button.h"

SW_API sw_button_state_t sw_button_set_state(
    sw_button_t *widget, sw_button_state_t state)
{
    widget->data.state = state;
    return state;
}

SW_API void *sw_button_get_user_data(sw_button_t *widget)
{
    return widget->data.user_data;
}

SW_API void *sw_button_set_user_data(sw_button_t *widget, void *user_data)
{
    widget->data.user_data = user_data;
    return user_data;
}

SW_API sw_result_t sw_button_set_texture(sw_button_t *widget,
    sfTexture const *texture, sw_button_state_t state, bool reset_rect)
{
    int e = state == SW_BUTTON_STATE_COUNT ? SW_BUTTON_STATE_COUNT : state + 1;
    sw_vec2u_t tsize;
    sw_result_t res = SW_OK;
    sfSprite **sprites = widget->data.sprites;

    if (reset_rect)
        tsize = sfTexture_getSize(texture);
    for (int i = state == SW_BUTTON_STATE_COUNT ? 0 : state; i < e; ++i) {
        if (reset_rect)
            widget->data.sprites_size[i] = (sw_vec2i_t){tsize.x, tsize.y};
        if (sprites[i] == NULL)
            sprites[i] = sfSprite_create();
        res = sprites[i] == NULL ? SW_ERR_ALLOCATION : SW_OK;
        if (sprites[i] != NULL)
            sfSprite_setTexture(sprites[i], texture, reset_rect);
    }
    return res;
}

SW_API sw_result_t sw_button_set_texture_rect(
    sw_button_t *widget, sw_irect_t rect, sw_button_state_t state)
{
    int e = state == SW_BUTTON_STATE_COUNT ? SW_BUTTON_STATE_COUNT : state + 1;
    sw_result_t res = SW_OK;
    sfSprite **sprites = widget->data.sprites;

    for (int i = state == SW_BUTTON_STATE_COUNT ? 0 : state; i < e; ++i) {
        widget->data.sprites_size[i] = (sw_vec2i_t){rect.width, rect.height};
        if (sprites[i] == NULL)
            sprites[i] = sfSprite_create();
        res = sprites[i] == NULL ? SW_ERR_ALLOCATION : SW_OK;
        if (sprites[i] != NULL)
            sfSprite_setTextureRect(widget->data.sprites[i], rect);
    }
    return res;
}
