/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Checks for invalid values in settings
*/

#include <SFML/Window/VideoMode.h>

#include "GameEngine/settings.h"
#include "functions.h"

void settings_check(settings_t *set)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    float ratio;

    CLAMP_ASSIGN(set->window_size.x, 500, mode.width);
    CLAMP_ASSIGN(set->window_size.y, 281, mode.height);
    CLAMP_ASSIGN(set->max_fps, 20, 300);
    CLAMP_ASSIGN(set->sound_volume, 0, 100);
    CLAMP_ASSIGN(set->music_volume, 0, 100);
    ratio = set->window_size.x / set->window_size.y - 16.f / 9.f;
    if (ABS(ratio) > 0.05f)
        set->window_size.y = 1080.f * (set->window_size.x / 1920.f);
    set->scale = set->window_size.x / 1920.f;
}
