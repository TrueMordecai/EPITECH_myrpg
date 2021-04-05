/*
** EPITECH PROJECT, 2020
** My runnger
** File description:
** Audio manager - update volumes
*/

#include "GameEngine/game_head.h"

void audio_manager_update_volume(audio_manager_t *manager)
{
    size_t nb_sounds = manager->sounds_playing.length;
    size_t nb_music = manager->music_playing.length;

    for (size_t i = 0; i < nb_sounds; i++) {
        sfSound_setVolume(
            MY_VEC_GET_ELEM(sfSound *, &manager->sounds_playing, i),
            manager->settings->sound_volume);
    }
    for (size_t i = 0; i < nb_music; i++) {
        sfMusic_setVolume(
            MY_VEC_GET_ELEM(sfSound *, &manager->music_playing, i),
            manager->settings->music_volume);
    }
}
