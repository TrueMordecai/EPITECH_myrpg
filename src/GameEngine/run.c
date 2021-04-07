/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Runs the game
*/

#include "GameEngine/game.h"

/*
** Times array:
** 0 = new_time
** 1 = current_time
** 2 = accumulator
*/
static void run_2(
    game_data_t *data, float times[2], sfClock *clock, state_t **current_state)
{
    float interpolation = 0;
    float init_ms = (1 / (float)data->settings->limit_framerate) * 1000;
    float ms_update = init_ms;

    times[0] = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    times[2] = times[2] + times[0] - times[1];
    if (times[2] > 10 * ms_update)
        ms_update = times[2];
    times[1] = times[0];
    (*current_state)->handle_events(*current_state);
    *current_state = (state_t *)my_vector_top((size_t *)data->states);
    while (times[2] >= ms_update) {
        (*current_state)->update(*current_state, ms_update / 1000.f);
        times[2] -= ms_update;
        update_sounds(data->audio, 0);
    }
    ms_update = init_ms;
    interpolation = times[2] / ms_update;
    (*current_state)->draw(*current_state, interpolation);
}

void run(game_data_t *data)
{
    sfClock *clock = sfClock_create();
    float times[3] = {0};
    state_t *current_state = (state_t *)my_vector_top((size_t *)data->states);

    times[1] = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    while (sfRenderWindow_isOpen(data->window))
        run_2(data, times, clock, &current_state);
    sfClock_destroy(clock);
}
