/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw settings
*/

#include "GameEngine/game.h"
#include "States/Settings/settings_state.h"

int settings_draw(settings_state_t *state, float dt)
{
    sfRenderWindow *window = state->base.game_data->window;
    size_t layer_count = state->base.draw_layers.length;

    sfRenderWindow_clear(window, sfColor_fromRGB(30, 30, 30));
    for (size_t layer = 0; layer < layer_count; ++layer)
        draw_map(my_vec_get(&state->base.draw_layers, layer), window);
    sfRenderWindow_display(window);
    return 0;
}
