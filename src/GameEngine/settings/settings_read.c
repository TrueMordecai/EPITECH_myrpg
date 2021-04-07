/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Reads the settings from a file
*/

#include <assert.h>
#include <stdlib.h>

#include "GameEngine/settings.h"

settings_t *settings_read(char const *path)
{
    settings_t *settings = malloc(sizeof(*settings));
    my_iostream_t input;
    int ret = 42;

    assert(path != NULL);
    if (settings == NULL)
        return NULL;
    if (my_fopen(path, "r", &input) == 0) {
        ret = settings_parse(settings, &input);
        my_fclose(&input);
    }
    if (ret != 0)
        settings_init_default(settings);
    else
        settings_check(settings);
    return settings;
}
