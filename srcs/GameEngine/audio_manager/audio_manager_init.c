/*
** EPITECH PROJECT, 2020
** GameEngine
** File description:
** audio manager functions
*/

#include "GameEngine/game_head.h"
#include "functions.h"

void init_audio_manager(audio_manager_t *audio_manager, \
game_settings_t *settings)
{
    audio_manager->sounds = my_map(char *, audio_t *, my_map_strcmp, 0, 1);
    audio_manager->musics = my_map(char *, audio_t *, my_map_strcmp, 0, 1);
    audio_manager->musics_playing = \
    (sfMusic **)my_vector_init(sizeof(sfMusic *), 3);
    audio_manager->sounds_playing = \
    (sfSound **)my_vector_init(sizeof(sfSound *), 10);
    audio_manager->settings = settings;
    load_audio(audio_manager);
}

void load_sound(audio_manager_t *audio_manager, char const *name, \
char const *filepath)
{
    audio_t *elmt = (audio_t *)my_map_find(audio_manager->sounds, \
    (size_t)name);
    sfSoundBuffer *sound;
    audio_t *audio;

    if (elmt != 0){
        return;
    }
    sound = sfSoundBuffer_createFromFile(filepath);
    if (sound == NULL)
        return;
    audio = malloc(sizeof(audio_t));
    audio->sound = sound;
    my_map_insert(audio_manager->sounds, (size_t)name, (size_t)audio);
}

void load_music(audio_manager_t *audio_manager, char const *name, \
char const *filepath)
{
    audio_t *elmt = (audio_t *)my_map_find(audio_manager->musics, (size_t)name);
    sfMusic *music;
    audio_t *audio;

    if (elmt != NULL)
        return;
    music = sfMusic_createFromFile(filepath);
    if (music == NULL)
        return;
    audio = malloc(sizeof(audio_t));
    audio->music = music;
    my_map_insert(audio_manager->musics, (size_t)name, (size_t)audio);
}

sfSoundBuffer *get_sound(audio_manager_t *audio_manager, char const *name)
{
    audio_t *elmt = (audio_t *)my_map_find(audio_manager->sounds, \
    (size_t)name);

    if (elmt == NULL)
        return NULL;
    return elmt->sound;
}

sfMusic *get_music(audio_manager_t *audio_manager, char const *name)
{
    audio_t *elmt = (audio_t *)my_map_find(audio_manager->musics, (size_t)name);

    if (elmt == NULL)
        return NULL;
    return elmt->music;
}