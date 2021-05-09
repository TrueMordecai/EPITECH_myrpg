/*
** EPITECH PROJECT, 2021
** Game Engine
** File description:
** game cycle
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "GameEngine/game.h"
#include "GameEngine/settings.h"
#include "GameEngine/particle_manager.h"
#include "States/Menu/menu_state.h"

static void init_window(game_data_t *data, sfVideoMode *mode, char const *name)
{
    data->window = sfRenderWindow_create(*mode, name, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(data->window, data->settings.max_fps);
}

game_data_t *game_data_create(sfVideoMode *mode, char const *name)
{
    game_data_t *data = malloc(sizeof(*data));

    if (data == NULL)
        return NULL;
    settings_read(&data->settings, SETTINGS_PATH);
    settings_write(&data->settings, SETTINGS_PATH);
    mode->width = data->settings.window_size.x;
    mode->height = data->settings.window_size.y;
    asset_manager_init(&data->assets);
    audio_manager_init(&data->audio, &data->settings);
    init_window(data, mode, name);
    my_vec_init_capacity(&data->states, 5, sizeof(state_t *));
    game_data_push_state(data, &menu_state_create, false);
    data->particles = particle_manager_create(&data->assets);
    return data;
}

static void game_data_destroy_state(void *state)
{
    state_destroy((state_t **)state, NULL_STATE);
}

void game_data_destroy(game_data_t *data)
{
    my_vec_free(&data->states, &game_data_destroy_state);
    asset_manager_drop(&data->assets);
    audio_manager_drop(&data->audio);
    sfRenderWindow_destroy(data->window);
    data->window = NULL;
    particle_manager_destroy(data->particles);
    data->particles = NULL;
    free(data);
}
