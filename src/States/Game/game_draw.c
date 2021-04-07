/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw game
*/

#include "States/Game/game_state.h"

int game_draw(game_state_t *state, float dt)
{
    sfRenderWindow *window = state->base.game_data->window;
    size_t layer_count = state->base.draw_layers.length;

    sfRenderWindow_clear(window, sfColor_fromRGB(18, 18, 18));
    for (size_t layer = 0; layer < layer_count; ++layer)
        draw_map(my_vec_get(&state->base.draw_layers, layer), window);
    rpg_draw(state->rpg);
    sfRenderWindow_display(window);
    return 0;
}
