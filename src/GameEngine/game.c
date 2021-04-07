/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** game cycle
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "GameEngine/game.h"
#include "GameEngine/settings.h"
#include "States/Menu/menu_state.h"

static void init_window(game_data_t *data, sfVideoMode *mode, char const *name)
{
    data->window = sfRenderWindow_create(*mode, name, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(
        data->window, data->settings->limit_framerate);
}

game_data_t *game_data_create(sfVideoMode *mode, char const *name)
{
    game_data_t *data = malloc(sizeof(*data));

    if (data == NULL)
        return NULL;
    data->settings = game_settings_create();
    if (data->settings == NULL) {
        free(data);
        return NULL;
    }
    mode->width = data->settings->wind_size.x;
    mode->height = data->settings->wind_size.y;
    init_asset_manager(&data->assets);
    init_audio_manager(&data->audio, data->settings);
    init_window(data, mode, name);
    my_vec_init_capacity(&data->states, 5, sizeof(state_t *));
    game_data_push_state(data, &menu_create, false);
    return data;
}

static void game_data_destroy_state(void *state)
{
    state_destroy((state_t **)state, NULL_STATE);
}

void game_data_destroy(game_data_t *data)
{
    my_vec_free(&data->states, &game_data_destroy_state);
    game_settings_destroy(data->settings);
    asset_manager_destroy(&data->assets);
    audio_manager_destroy(&data->audio);
    sfRenderWindow_destroy(data->window);
    free(data);
}
