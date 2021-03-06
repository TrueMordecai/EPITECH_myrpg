/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Writes the settings to a file
*/

#include <libmy/printf.h>

#include "GameEngine/settings.h"

int settings_write_to_stream(settings_t const *settings, my_iostream_t *output)
{
    if (my_fprintf(output,
            "# Game Engine Settings\nwindow.width = %u\nwindow.height = %u\n"
            "max_fps = %u\nsound.music = %u\nsound.misc = %u\n",
            settings->window_size.x, settings->window_size.y,
            settings->max_fps, (unsigned)settings->music_volume,
            (unsigned)settings->sound_volume)
        < 0)
        return 1;
    return 0;
}

// music volume and sound volume are currently written as unsigned ints
// because my_printf does not have support for floats yet.
int settings_write(settings_t const *settings, char const *path)
{
    my_iostream_t output;
    char buffer[256];

    if (my_fopen(path, "w+", &output)
        || my_fset_buffer(buffer, 256, NULL, &output)) {
        my_fprintf(
            MY_STDERR, "Couldn't open settings file for writing: %s\n", path);
        return 1;
    }
    if (settings_write_to_stream(settings, &output)) {
        my_fprintf(MY_STDERR, "Couldn't write settings file: %s\n", path);
        my_fclose(&output);
        return 1;
    }
    my_fclose(&output);
    return 0;
}
