/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** game cycle
*/

#include <time.h>
#include <unistd.h>
#include "GameEngine/game_head.h"
#include "States/Menu/menu_state.h"

void destroy_game(game_data_t *data)
{
    size_t nb_state = my_vector_get_size((size_t *)data->states);

    for (size_t i = 0; i < nb_state; i++){
        data->states[i]->destroy(data->states[i], NONE);
    }
    free(data->datas);
    free(data->settings);
    my_vector_free((size_t **)&data->states);
    asset_manager_destroy(&data->assets);
    destroy_audio_manager(&data->audio);
    sfRenderWindow_destroy(data->window);
    free(data);
}

static void init_window(game_data_t *data, sfVideoMode *mode, char const *name)
{
    data->window = sfRenderWindow_create(*mode, name, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(data->window, \
    data->settings->limit_framerate);
}

game_data_t *init_game(sfVideoMode *mode, char const *name)
{
    game_data_t *data = malloc(sizeof(game_data_t));

    data->datas = NULL;
    data->settings = game_settings_init();
    if (data->settings == NULL){
        free(data);
        return NULL;
    }
    mode->width = data->settings->wind_size.x;
    mode->height = data->settings->wind_size.y;
    data->assets = malloc(sizeof(asset_manager_t));
    data->audio = malloc(sizeof(audio_manager_t));
    init_asset_manager(data->assets);
    init_audio_manager(data->audio, data->settings);
    init_window(data, mode, name);
    data->states = (state_t **)my_vector_init(sizeof(state_t *), 5);
    add_state(data, &menu_create, 0, 0);
    return data;
}

static void run_2(game_data_t *data, float *times, sfClock *clock, \
state_t **current_state)
{
    float interpolation = 0;

    times[0] = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    times[2] = MIN(times[2] + times[0] - times[1], 10 * MS_UPDATE);
    times[1] = times[0];
    (*current_state)->handle_input(*current_state);
    *current_state = (state_t *)my_vector_top((size_t *)data->states);
    while (times[2] >= MS_UPDATE) {
        (*current_state)->update(*current_state, MS_UPDATE / 1000.f);
        times[2] -= MS_UPDATE;
        update_sounds(data->audio, 0);
    }
    interpolation = times[2] / MS_UPDATE;
    (*current_state)->draw(*current_state, interpolation);
}

/*
** Times array:
** 0 = new_time
** 1 = current_time
** 2 = accumulator
*/
void run(game_data_t *data)
{
    sfClock *clock = sfClock_create();
    float times[3] = {0};
    state_t *current_state =(state_t *)my_vector_top((size_t *)data->states);

    times[1] = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    while (sfRenderWindow_isOpen(data->window))
        run_2(data, times, clock, &current_state);
    sfClock_destroy(clock);
}
