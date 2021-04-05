/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game engine - audio manager
*/

#include "GameEngine/game_head.h"

void play_sound(audio_manager_t *audio_manager, char const *name)
{
    sfSoundBuffer *buffer = get_sound(audio_manager, name);
    sfSound *sound;

    if (buffer == NULL)
        return;
    sound = sfSound_create();
    sfSound_setBuffer(sound, buffer);
    sfSound_setVolume(sound, audio_manager->settings->sound_volume);
    sfSound_play(sound);
    my_vector_push((size_t **)&audio_manager->sounds_playing, (size_t)sound);
}

void play_music(audio_manager_t *audio_manager, char const *name, int loop)
{
    sfMusic *music = get_music(audio_manager, name);

    if (music == NULL)
        return;
    sfMusic_setVolume(music, audio_manager->settings->music_volume);
    sfMusic_setLoop(music, loop);
    sfMusic_play(music);
    my_vector_push((size_t **)&audio_manager->musics_playing, (size_t)music);
}

void update_sounds(audio_manager_t *audio_manager, int stop_all)
{
    size_t nb_sounds = \
    my_vector_get_size((size_t *)audio_manager->sounds_playing);

    for (size_t i = 0; i < nb_sounds; i++){
        if (stop_all || \
        sfSound_getStatus(audio_manager->sounds_playing[i]) == sfStopped){
            sfSound_destroy(audio_manager->sounds_playing[i]);
            my_vector_erase((size_t *)audio_manager->sounds_playing, i, 0);
            i--;
            nb_sounds--;
        }
    }
}

void stop_musics(audio_manager_t *audio_manager)
{
    size_t nb_musics = \
    my_vector_get_size((size_t *)audio_manager->musics_playing);

    for (size_t i = 0; i < nb_musics; i++)
        sfMusic_stop(audio_manager->musics_playing[i]);
    my_vector_clear((size_t *)audio_manager->musics_playing, 0);
}

void destroy_audio_manager(audio_manager_t **manager_adr)
{
    audio_manager_t *manager = *manager_adr;
    size_t nb_buffers = my_map_size(manager->sounds);
    size_t nb_musics = my_map_size(manager->musics);

    update_sounds(manager, 1);
    stop_musics(manager);
    my_vector_free((size_t **)&manager->musics_playing);
    my_vector_free((size_t **)&manager->sounds_playing);
    for (size_t i = 0; i < nb_buffers; i++)
        sfSoundBuffer_destroy(\
        ((audio_t *)my_map_at(manager->sounds, i))->sound);
    for (size_t i = 0; i < nb_musics; i++)
        sfMusic_destroy(((audio_t *)my_map_at(manager->musics, i))->music);
    my_map_free(&manager->musics);
    my_map_free(&manager->sounds);
    free(manager);
    *manager_adr = 0;
}