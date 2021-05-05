/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Frees the contents of a config structure
*/

#include <assert.h>
#include <stdalign.h>

#include "GameEngine/settings.h"

void cfg_file_drop(cfg_file_t *cfg)
{
    if (cfg == NULL)
        return;
    my_hash_map_drop(&cfg->data);
}
