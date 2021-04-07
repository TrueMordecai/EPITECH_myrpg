/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw menu
*/

#include "Drawables/drawable.h"
#include "GameEngine/game.h"
#include "States/Menu/menu_state.h"

int menu_state_draw(menu_state_t *state, float dt)
{
    sfRenderWindow *window = state->base.game_data->window;
    size_t layer_count = state->base.draw_layers.length;

    sfRenderWindow_clear(window, sfColor_fromRGB(18, 18, 18));
    for (size_t layer = 0; layer < layer_count; ++layer)
        draw_map(my_vec_get(&state->base.draw_layers, layer), window);
    sfRenderWindow_display(window);
    return 0;
}
