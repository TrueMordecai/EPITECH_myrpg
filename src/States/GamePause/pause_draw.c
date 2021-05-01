/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw game
*/

#include "Drawables/drawable.h"
#include "States/GamePause/pause_state.h"
#include "GameEngine/game_head.h"

int pause_state_draw(pause_state_t *state, float dt)
{
    sfRenderWindow *window = state->base.game_data->window;
    size_t layer_count = state->base.draw_layers.length;

    sfRenderWindow_clear(window, sfColor_fromRGB(50, 50, 50));
    for (size_t layer = 0; layer < layer_count; ++layer)
        draw_from_map(my_vec_get(&state->base.draw_layers, layer), window);
    sw_draw(state->gui_base, window, NULL);
    sfRenderWindow_display(window);
    (void)dt;
    return 0;
}
