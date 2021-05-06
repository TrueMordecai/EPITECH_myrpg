/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Inits a config file structure
*/

#include <assert.h>
#include <stdalign.h>

#include "GameEngine/settings.h"

void cfg_file_init(cfg_file_t *cfg)
{
    my_map_kvtypes_t kvtypes;

    assert(cfg != NULL);
    kvtypes = (my_map_kvtypes_t){
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(char *),
        .value_align = alignof(char *),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
        .key_drop = MY_HASH_MAP_CSTR_DROP,
        .value_drop = MY_HASH_MAP_CSTR_DROP,
    };
    my_hash_map_init(&cfg->data, &kvtypes);
}
