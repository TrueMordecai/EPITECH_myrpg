/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Destroys settings
*/

#include <stdlib.h>

#include "GameEngine/settings.h"

void settings_destroy(settings_t *settings)
{
    free(settings);
}
