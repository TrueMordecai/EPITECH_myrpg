/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Checks for invalid values in settings
*/

#include <SFML/Window/VideoMode.h>
#include <libmy/core.h>

#include "GameEngine/settings.h"

void settings_check(settings_t *set)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    float ratio;

    set->wind_size.x = MY_MAX(500, MY_MIN(set->wind_size.x, mode.width));
    set->wind_size.x = MY_MAX(281, MY_MIN(set->wind_size.y, mode.height));
    set->limit_framerate = MY_MAX(20, MY_MIN(set->limit_framerate, 300));
    set->sound_volume = MY_MAX(0, MY_MIN(set->sound_volume, 100));
    set->music_volume = MY_MAX(0, MY_MIN(set->music_volume, 100));
    ratio = set->wind_size.x / set->wind_size.y - 16.f / 9.f;
    if (MY_ABS(ratio) > 0.05f)
        set->wind_size.y = 1080.f * (set->wind_size.x / 1920.f);
    set->scale = set->wind_size.x / 1920.f;
}
