/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Gets values by key
*/

#include <assert.h>
#include <libmy/parsing/parsing.h>

#include "GameEngine/settings.h"

bool cfg_file_get_str_value(
    cfg_file_t *cfg, char const *key, char const **value)
{
    char const **tmp;

    assert(cfg != NULL);
    assert(key != NULL);
    assert(value != NULL);
    tmp = my_hash_map_get(&cfg->data, &key);
    if (tmp == NULL)
        return false;
    *value = *tmp;
    return true;
}

bool cfg_file_get_uint_value(cfg_file_t *cfg, char const *key, unsigned *value)
{
    char const *str_value;
    unsigned tmp;

    assert(value != NULL);
    cfg_file_get_str_value(cfg, key, &str_value);
    if (my_next_uint(&str_value, &tmp))
        return false;
    *value = tmp;
    return true;
}
