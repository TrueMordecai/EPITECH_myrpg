/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Initializes the settings with default values
*/

#include <SFML/Window/VideoMode.h>
#include <libmy/core.h>

#include "GameEngine/settings.h"

void settings_init_default(settings_t *settings)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    unsigned width = MY_MAX(1280, mode.width);
    unsigned height = MY_MAX(720, mode.height);

    *settings = (settings_t){
        .wind_size = (sfVector2u){width, height},
        .limit_framerate = 60,
        .music_volume = 100,
        .sound_volume = 100,
        .scale = (float)width / 1920.f,
    };
}
