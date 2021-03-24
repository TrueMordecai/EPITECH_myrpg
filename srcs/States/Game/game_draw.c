/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw game
*/

#include "States/Game/game_state.h"

int game_draw(state_t *state, float dt)
{
    sfRenderWindow *window = state->game_data->window;
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    sfRenderWindow_clear(window, sfColor_fromRGB(0, 0, 0));
    for (size_t layer = 0; layer < nb_layers; layer++){
        draw_map(state->draw_layers[layer], window);
    }
    rpg_draw((rpg_t *)state->state_datas);
    sfRenderWindow_display(window);
    return 1;
}
