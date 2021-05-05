/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Game engine - audio manager
*/

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>

#include "GameEngine/audio_manager.h"

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
    my_vec_push(&audio_manager->sounds_playing, &sound);
}

void play_music(audio_manager_t *audio_manager, char const *name, bool loop)
{
    sfMusic *music = get_music(audio_manager, name);

    if (music == NULL)
        return;
    sfMusic_setVolume(music, audio_manager->settings->music_volume);
    sfMusic_setLoop(music, loop);
    sfMusic_play(music);
    my_vec_push(&audio_manager->music_playing, &music);
}

void update_sounds(audio_manager_t *audio_manager, bool stop_all)
{
    size_t sounds_count = audio_manager->sounds_playing.length;

    for (size_t i = 0; i < sounds_count; ++i) {
        sfSound *sound =
            MY_VEC_GET_ELEM(sfSound *, &audio_manager->sounds_playing, i);

        if (stop_all || sfSound_getStatus(sound) == sfStopped) {
            sfSound_destroy(sound);
            my_vec_remove(&audio_manager->sounds_playing, NULL, i--);
            --sounds_count;
        }
    }
}

void stop_music(audio_manager_t *audio_manager)
{
    size_t music_count = audio_manager->music_playing.length;

    for (size_t i = 0; i < music_count; ++i)
        sfMusic_stop(
            MY_VEC_GET_ELEM(sfMusic *, &audio_manager->music_playing, i));
    audio_manager->music_playing.length = 0;
}
