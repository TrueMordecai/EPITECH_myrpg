/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Writes the settings to a file
*/

#include <libmy/printf.h>

#include "GameEngine/settings.h"

// music volume and sound volume are currently written as unsigned ints
// because my_printf does not have support for floats yet.
int settings_write(settings_t *settings, char const *path)
{
    my_iostream_t output;

    if (my_fopen(path, "w+", &output)) {
        my_fprintf(
            MY_STDERR, "Couldn't open settings file for writing: %s\n", path);
        return 1;
    }
    if (my_fprintf(&output, "%ux%u\n%u\n%u\n%u\n%u", settings->window_size.x,
            settings->window_size.y, settings->max_framerate,
            (unsigned)settings->music_volume, (unsigned)settings->sound_volume)
        < 0) {
        my_fprintf(MY_STDERR, "Couldn't write settings file: %s\n", path);
        my_fclose(&output);
        return 1;
    }
    my_fclose(&output);
    return 0;
}
