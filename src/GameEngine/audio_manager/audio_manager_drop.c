/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Game Engine - uninitializes the audio manager
*/

#include <SFML/Audio/Music.h>
#include <SFML/Audio/SoundBuffer.h>

#include "GameEngine/audio_manager.h"

void audio_manager_drop(audio_manager_t *manager)
{
    update_sounds(manager, 1);
    stop_music(manager);
    my_vec_free(&manager->music_playing, NULL);
    my_vec_free(&manager->sounds_playing, NULL);
    my_hash_map_drop(&manager->music);
    my_hash_map_drop(&manager->sounds);
}

void music_audio_drop(audio_t *audio)
{
    if (audio->music != NULL) {
        sfMusic_destroy(audio->music);
        audio->music = NULL;
    }
}

void sound_audio_drop(audio_t *audio)
{
    if (audio->sound != NULL) {
        sfSoundBuffer_destroy(audio->sound);
        audio->sound = NULL;
    }
}
