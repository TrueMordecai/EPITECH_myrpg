/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The button widget, part 3
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>

#include "sw/widget.h"
#include "sw/widgets/button.h"

SW_PROTECTED_API void sw_button_drop(sw_button_t *widget)
{
    sfSprite **sprites = widget->data.sprites;

    sw_base_drop(&widget->base);
    if (widget->data.text != NULL) {
        sfText_destroy(widget->data.text);
        widget->data.text = NULL;
    }
    for (int i = 0; i < SW_BUTTON_STATE_COUNT; ++i) {
        if (sprites[i] != NULL) {
            sfSprite_destroy(sprites[i]);
            sprites[i] = NULL;
        }
    }
}

SW_PROTECTED_API void sw_button_draw(
    sw_button_t *widget, sfRenderWindow *window, sw_state_t const *state)
{
    sfSprite *sprite = widget->data.sprites[widget->data.state];

    sw_base_draw(&widget->base, window, state);
    if (sprite != NULL)
        sfRenderWindow_drawSprite(window, sprite, &state->render_states);
    if (widget->data.has_text)
        sfRenderWindow_drawText(
            window, widget->data.text, &state->render_states);
}

SW_PROTECTED_API void sw_button_set_size(
    sw_button_t *widget, sw_vec2f_t new_size)
{
    sw_vec2f_t pos = SW_POS(widget);

    sw_base_set_size(&widget->base, new_size);
    sfText_setPosition(widget->data.text,
        (sw_vec2f_t){pos.x + new_size.x / 2, pos.y / new_size.y / 2});
    for (int i = 0; i < SW_BUTTON_STATE_COUNT; ++i) {
        sw_vec2i_t ssize = widget->data.sprites_size[i];
        sw_vec2f_t scale = {ssize.x == 0 ? 0 : new_size.x / ssize.x,
            ssize.y == 0 ? 0 : new_size.y / ssize.y};

        if (widget->data.sprites[i] != NULL)
            sfSprite_setScale(widget->data.sprites[i], scale);
    }
}

SW_PROTECTED_API void sw_button_set_position(
    sw_button_t *widget, sw_vec2f_t new_pos)
{
    sw_vec2f_t size = SW_SIZE(widget);

    sw_base_set_position(&widget->base, new_pos);
    sfText_setPosition(widget->data.text,
        (sw_vec2f_t){new_pos.x + size.x / 2, new_pos.y + size.y / 2});
    for (int i = 0; i < SW_BUTTON_STATE_COUNT; ++i)
        sfSprite_setPosition(widget->data.sprites[i], new_pos);
}
