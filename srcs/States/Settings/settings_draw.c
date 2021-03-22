/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw settings
*/

#include "States/Settings/settings_state.h"

int settings_draw(state_t *state, float dt)
{
    sfRenderWindow *window = state->game_data->window;
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    sfRenderWindow_clear(window, sfColor_fromRGB(30, 30, 30));
    for (size_t layer = 0; layer < nb_layers; layer++){
        draw_map(state->draw_layers[layer], window);
    }
    sfRenderWindow_display(window);
    return 1;
}