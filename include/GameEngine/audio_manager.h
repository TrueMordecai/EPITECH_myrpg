/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GameEngine - sound manager
*/

#ifndef GE_AUDIO_MANAGER_H
#define GE_AUDIO_MANAGER_H

#include <SFML/Audio.h>

typedef union {
    struct sfMusic *music;
    struct sfSoundBuffer *sound;
} audio_t;

typedef struct audio_manager_t {
    struct my_map_t *musics;
    struct my_map_t *sounds;
    struct sfMusic **musics_playing;
    struct sfSound **sounds_playing;
    struct game_settings_t *settings;
} audio_manager_t;

void init_audio_manager(audio_manager_t *audio_manager, \
struct game_settings_t *settings);
void load_audio(audio_manager_t *manager);
void destroy_audio_manager(audio_manager_t **manager_adr);

void load_sound(audio_manager_t *audio_manager, char const *name, \
char const *filepath);
struct sfSoundBuffer *get_sound(audio_manager_t *audio_manager, \
char const *name);
void play_sound(audio_manager_t *audio_manager, char const *name);
void update_sounds(audio_manager_t *audio_manager, int stop_all);
void audio_manager_update_volumes(audio_manager_t *manager);

void load_music(audio_manager_t *audio_manager, char const *name, \
char const *filepath);
struct sfMusic *get_music(audio_manager_t *audio_manager, char const *name);
void play_music(audio_manager_t *audio_manager, char const *name, int loop);
void stop_musics(audio_manager_t *audio_manager);

#endif /* !GE_AUDIO_MANAGER_H */