/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Reads a key-value configuration file
*/

#include <assert.h>
#include <libmy/ascii/ascii.h>
#include <libmy/ascii/character.h>
#include <limits.h>
#include <stdlib.h>

#include "GameEngine/settings.h"

int cfg_file_read(cfg_file_t *cfg, char const *path, bool strict)
{
    my_iostream_t input;
    char buffer[256];
    int ret;

    assert(path != NULL);
    if (my_fopen(path, "r", &input)
        || my_fset_buffer(buffer, 256, NULL, &input)) {
        my_fclose(&input);
        return -1;
    }
    ret = cfg_file_read_from_stream(cfg, &input, strict);
    my_fclose(&input);
    return ret;
}

static int cfg_file_parse_line(cfg_file_t *cfg, char const *line)
{
    char const *key = line;
    char const *val;
    size_t key_len;
    size_t val_len;

    while (*line != '\0' && !my_isspace(*line))
        ++line;
    key_len = line - key;
    while (*line != '\0' && my_isspace(*line))
        ++line;
    if (*line != '=')
        return 1;
    while (*(++line) != '\0' && my_isspace(*line))
        ;
    val = line;
    while (*line != '\0' && *line != '#' && *line != '\n')
        ++line;
    val_len = line - val;
    key = my_strndup(key, key_len);
    val = my_strndup(val, val_len);
    if (key == NULL || val == NULL) {
        free((void *)key);
        free((void *)val);
        return 1;
    }
    return my_hash_map_insert(&cfg->data, &key, &val) != MY_MAP_OK;
}

int cfg_file_read_from_stream(
    cfg_file_t *cfg, my_iostream_t *input, bool strict)
{
    char *line = NULL;
    int current_line = 1;
    size_t alloc_size = 0;

    assert(cfg != NULL);
    assert(input != NULL);
    while (my_getline(&line, &alloc_size, input) > 0) {
        while (my_isspace(*line))
            ++line;
        if (*line != '#' && cfg_file_parse_line(cfg, line) && strict) {
            free(line);
            return current_line;
        }
        ++current_line;
    }
    free(line);
    return my_feof(input) ? 0 : -current_line - 1;
}
