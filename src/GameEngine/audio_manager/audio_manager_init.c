/*
** EPITECH PROJECT, 2020
** GameEngine
** File description:
** audio manager functions
*/

#include <stdalign.h>

#include "functions.h"
#include "GameEngine/game_head.h"

void init_audio_manager(
    audio_manager_t *audio_manager, game_settings_t *settings)
{
    const my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(audio_t),
        .value_align = alignof(audio_t),
        .hash = MY_HASH_MAP_CSTR_HASH,
        .compare = MY_HASH_MAP_CSTR_CMP,
    };

    my_hash_map_init(&audio_manager->sounds, &kvtypes);
    my_hash_map_init(&audio_manager->music, &kvtypes);
    my_vec_init_capacity(&audio_manager->music_playing, 3, sizeof(sfMusic *));
    my_vec_init_capacity(
        &audio_manager->sounds_playing, 10, sizeof(sfMusic *));
    audio_manager->settings = settings;
    load_audio(audio_manager);
}

void load_sound(
    audio_manager_t *audio_manager, char const *name, char const *filepath)
{
    audio_t audio;

    if (my_hash_map_contains(&audio_manager->sounds, &name))
        return;
    audio.sound = sfSoundBuffer_createFromFile(filepath);
    if (audio.sound == NULL)
        return;
    my_hash_map_insert(&audio_manager->sounds, &name, &audio);
}

void load_music(
    audio_manager_t *audio_manager, char const *name, char const *filepath)
{
    audio_t audio;

    if (my_hash_map_contains(&audio_manager->sounds, &name))
        return;
    audio.music = sfMusic_createFromFile(filepath);
    if (audio.sound == NULL)
        return;
    my_hash_map_insert(&audio_manager->sounds, &name, &audio);
}

sfSoundBuffer *get_sound(audio_manager_t *audio_manager, char const *name)
{
    audio_t *audio = my_hash_map_get(&audio_manager->sounds, &name);

    return audio == NULL ? NULL : audio->sound;
}

sfMusic *get_music(audio_manager_t *audio_manager, char const *name)
{
    audio_t *audio = my_hash_map_get(&audio_manager->sounds, &name);

    return audio == NULL ? NULL : audio->music;
}
