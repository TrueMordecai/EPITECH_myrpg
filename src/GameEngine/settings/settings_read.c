/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Reads the settings from a file
*/

#include <assert.h>
#include <libmy/memory/alloc.h>
#include <stdlib.h>

#include "GameEngine/settings.h"

settings_t *settings_read(char const *path)
{
    settings_t *settings;
    cfg_file_t cfg;

    assert(path != NULL);
    settings = malloc(sizeof(*settings));
    if (settings == NULL)
        return NULL;
    cfg_file_init(&cfg);
    if (cfg_file_read(&cfg, path, false) == 0) {
        settings_parse(settings, &cfg);
        settings_check(settings);
    } else {
        settings_init_default(settings);
    }
    cfg_file_drop(&cfg);
    return settings;
}
