/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GameEngine - sound manager
*/

#ifndef GE_AUDIO_MANAGER_H
#define GE_AUDIO_MANAGER_H

#include <SFML/Audio.h>
#include <libmy/collections.h>

#include "types.h"

#include "settings.h"

union audio {
    sfMusic *music;
    sfSoundBuffer *sound;
};

struct audio_manager {
    /// key type: 'char *'
    /// Value value: 'audio_t *'
    my_hash_map_t music;
    /// Key type: 'char *'
    /// Value value: 'audio_t *'
    my_hash_map_t sounds;
    /// Stores @b references to the music tracks currently playing.
    /// Element type: 'sfMusic *'
    my_vec_t music_playing;
    /// Stores @b references to the sounds currently playing.
    /// Element type: 'sfSound *'
    my_vec_t sounds_playing;
    game_settings_t *settings;
};

void audio_manager_init(
    audio_manager_t *audio_manager, game_settings_t *settings);
void load_audio(audio_manager_t *manager);
void audio_manager_drop(audio_manager_t *manager);

void load_sound(
    audio_manager_t *audio_manager, char const *name, char const *filepath);
sfSoundBuffer *get_sound(audio_manager_t *audio_manager, char const *name);
void play_sound(audio_manager_t *audio_manager, char const *name);
void update_sounds(audio_manager_t *audio_manager, int stop_all);
void audio_manager_update_volume(audio_manager_t *manager);

void load_music(
    audio_manager_t *audio_manager, char const *name, char const *filepath);
sfMusic *get_music(audio_manager_t *audio_manager, char const *name);
void play_music(audio_manager_t *audio_manager, char const *name, int loop);
void stop_music(audio_manager_t *audio_manager);

/// Frees the inner @c sfMusic of an audio value,
/// for use inside the music map of @ref audio_manager_t.
void music_audio_drop(audio_t *audio);

/// Frees the inner @c sfSoundBuffer of an audio value,
/// for use inside the music map of @ref audio_manager_t.
void sound_audio_drop(audio_t *audio);

#endif /* !GE_AUDIO_MANAGER_H */
