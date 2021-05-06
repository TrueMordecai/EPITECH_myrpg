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

void settings_read(settings_t *settings, char const *path)
{
    cfg_file_t cfg;

    assert(path != NULL);
    cfg_file_init(&cfg);
    if (cfg_file_read(&cfg, path, false) == 0) {
        settings_parse(settings, &cfg);
        settings_check(settings);
    } else {
        settings_init_default(settings);
    }
    cfg_file_drop(&cfg);
}
