/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Draws the settings menu
*/

#include <sw/widget.h>

#include "Drawables/drawable.h"
#include "GameEngine/game.h"
#include "States/Settings/settings_state.h"

int settings_state_draw(settings_state_t *state, float dt)
{
    sfRenderWindow *window = state->base.game_data->window;
    size_t layer_count = state->base.draw_layers.length;

    sfRenderWindow_clear(window, sfColor_fromRGB(30, 30, 30));
    for (size_t layer = 0; layer < layer_count; ++layer)
        draw_from_map(my_vec_get(&state->base.draw_layers, layer), window);
    sw_draw(&state->gui, window, NULL);
    sfRenderWindow_display(window);
    (void)dt;
    return 0;
}
