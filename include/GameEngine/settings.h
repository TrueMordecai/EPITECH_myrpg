/*
<<<<<<< HEAD
** EPITECH PROJECT, 2020
** Game Engine
=======
** EPITECH PROJECT, 2021
** MyRPG
>>>>>>> master
** File description:
** Game engine - settings
*/

#ifndef GE_SETTINGS_H
#define GE_SETTINGS_H

#include <SFML/System/Vector2.h>
#include <libmy/io/iostream.h>
#include <stdbool.h>
#include <libmy/collections/hash_map.h>

#include "types.h"

#define SCL(state) (state->base.game_data->settings.scale)
#define SL(rpg)    ((rpg)->state->game_data->settings.scale)

/// A runtime representation of a config file.
///
/// config file lines of key-value pairs formatted as follows
/// <code>KEY = VALUE</code>
/// <code>MULTI WORD KEY = VALUE WORD2 ...</code>
///
/// @c KEY is a string of any characters except equal ('='),
/// and hash signs ('#').
///
/// @c VALUE is a string comprising any character execpt the hash sign ('#'),
//  it starts at the first non-whitespace character after the equals
/// separator and ends with the last non-whitespace character of the line
/// (excluding end-of-line comment).
///
/// Config file may contain comments, starting by the hash sign ('#'), they
/// span the rest of line and can by placed either on their own lines or at the
/// end of a key-value line.

struct cfg_file {
    /// Key type: char * (allocated)
    /// Value type: char * (allocated)
    /// @private
    my_hash_map_t data;
};

/// Intializes the config file structure.
///
/// @param cfg The config file structure, must not be @c NULL.
void cfg_file_init(cfg_file_t *cfg);

/// Frees the contents of the config file structure.
///
/// NOTE: any references to keys or values from this structure @b will become
/// invalid.
///
/// @param cfg The config file structure, may be @c NULL.
void cfg_file_drop(cfg_file_t *cfg);

/// Reads the contents of the config file at @c path to the structure @c cfg.
///
/// @param cfg The config file structure, must not be @c NULL and
/// be initialized by @ref cfg_file_init first.
/// @param path Where the config file to read is located.
/// @param strict Whether the parsing should stop when encountering an error.
///
/// @returns 0 on success, -1 if @c path could not be opened.
/// if errored on strict mode, returns the line index where the error occured,
/// or <code>-line_index - 1</code> if a read error occered at @c line_index
/// (starting at 1).
int cfg_file_read(cfg_file_t *cfg, char const *path, bool strict);

/// Reads the contents of the config file from @c input to the
/// structure @c cfg.
///
/// @param cfg The config file structure, must not be @c NULL and
/// be initialized by @ref cfg_file_init first.
/// @param input The input stream, must not be @c NULL.
/// @param strict Whether the parsing should stop when encountering an error.
///
/// @returns 0 on success, -1 if @c path could not be opened.
/// if errored on strict mode, returns the line index where the error occured,
/// or <code>-line_index - 1</code> if a read error occered at @c line_index
/// (starting at 1).
int cfg_file_read_from_stream(
    cfg_file_t *cfg, my_iostream_t *input, bool strict);

/// Fetches the string value associated with @c key.
///
/// @param cfg The config file structure, must not be @c NULL and
/// be initialized by @ref cfg_file_init first.
/// @param key The pair's key.
/// @param value Where the value is stored if the key exists.
///
/// @returns Whether the operation succeded.
bool cfg_file_get_str_value(
    cfg_file_t *cfg, char const *key, char const **value);

/// Fetches the unsigned int value associated with @c key.
///
/// @param cfg The config file structure, must not be @c NULL and
/// be initialized by @ref cfg_file_init first.
/// @param key The pair's key.
/// @param value Where the value is stored if the key exists and is a value
/// unsigned int.
///
/// @returns Whether the operation succeded.
bool cfg_file_get_uint_value(
    cfg_file_t *cfg, char const *key, unsigned *value);

/// Game engine settings.
struct settings {
    sfVector2u window_size;
    unsigned int max_fps;
    float music_volume;
    float sound_volume;
    float scale;
};

/// Initalizes and read settings from the given path,
/// if @c path cannot be opened, @ref settings_init_default
/// is used to popolate the values.
void settings_read(settings_t *settings, char const *path);

/// Writes the current settings to the file at @c path.
///
/// @param settings The settings, must not be @c NULL.
/// @param path The path to the settings file, must either not exist or point
/// to a regular file (symlinks are OK).
///
/// @returns 0, on success.
int settings_write(settings_t const *settings, char const *path);

/// Writes the current settings to the file at @c stream.
///
/// @param settings The settings, must not be @c NULL.
/// @param output The output stream, must not be @c NULL.
///
/// @returns 0, on success.
int settings_write_to_stream(
    settings_t const *settings, my_iostream_t *output);

/// Sets the given settings to their default values.
void settings_init_default(settings_t *settings);

/// Parses the settings from the key-value store.
/// Any missing or invalid key-value pair is set to its default value,
/// as set by @ref settings_init_default.
void settings_parse(settings_t *settings, cfg_file_t *cfg);

/// Checks for any invalid value and corrects them.
void settings_check(settings_t *settings);

#endif // !defined(GE_SETTINGS_H)
