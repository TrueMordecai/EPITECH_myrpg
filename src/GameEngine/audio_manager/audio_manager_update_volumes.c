/*
** EPITECH PROJECT, 2020
** My runnger
** File description:
** Audio manager - update volumes
*/

#include "GameEngine/game_head.h"

void audio_manager_update_volumes(audio_manager_t *manager)
{
    size_t nb_sounds = \
    my_vector_get_size((size_t *)manager->sounds_playing);
    size_t nb_musics = \
    my_vector_get_size((size_t *)manager->musics_playing);

    for (size_t i = 0; i < nb_sounds; i++){
        sfSound_setVolume(manager->sounds_playing[i], \
        manager->settings->sound_volume);
    }
    for (size_t i = 0; i < nb_musics; i++){
        sfMusic_setVolume(manager->musics_playing[i], \
        manager->settings->music_volume);
    }
}