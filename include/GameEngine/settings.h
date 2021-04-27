/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game engine - settings
*/

#ifndef GE_SETTINGS_H
#define GE_SETTINGS_H

#include <SFML/System/Vector2.h>
#include <libmy/io/iostream.h>

#include "types.h"

#define SCL(state) (state->base.game_data->settings->scale)
#define SL(rpg)    ((rpg)->state->game_data->settings->scale)

struct settings {
    sfVector2u window_size;
    unsigned int max_fps;
    float music_volume;
    float sound_volume;
    float scale;
};

/// Creates and read settings from the given path, if @c path cannot be opened,
/// @ref settings_init_default is used to popolate the values.
settings_t *settings_read(char const *path);

/// Sets the given settings to their default values.
void settings_init_default(settings_t *settings);

/// Writes the settings to the given path.
int settings_write(settings_t *settings, char const *path);

/// Frees the passed settings.
void settings_destroy(settings_t *settings);

/// Parses the settings from the input stream.
int settings_parse(settings_t *settings, my_iostream_t *input);

/// Checks for any invalid value and corrects them.
void settings_check(settings_t *settings);

#endif /* !GE_SETTINGS_H */
