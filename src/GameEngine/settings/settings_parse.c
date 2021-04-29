/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Parses the input stream
*/

#include "GameEngine/settings.h"

void settings_parse(settings_t *settings, cfg_file_t *cfg)
{
    unsigned tmp;

    assert(settings != NULL);
    assert(cfg != NULL);
    settings_init_default(settings);
    cfg_file_get_uint_value(cfg, "window.width", &settings->window_size.x);
    cfg_file_get_uint_value(cfg, "window.height", &settings->window_size.y);
    cfg_file_get_uint_value(cfg, "max_fps", &settings->max_fps);
    if (cfg_file_get_uint_value(cfg, "sound.music", &tmp))
        settings->music_volume = (float)tmp;
    if (cfg_file_get_uint_value(cfg, "sound.misc", &tmp))
        settings->sound_volume = (float)tmp;
}
