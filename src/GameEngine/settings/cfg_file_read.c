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
#include "functions.h"

int cfg_file_read(cfg_file_t *cfg, char const *path, bool strict)
{
    my_iostream_t input;
    char buffer[256];
    int ret;

    assert(path != NULL);
    if (my_fopen(path, "r", &input))
        return -1;
    if (my_fset_buffer(buffer, 256, NULL, &input)) {
        my_fclose(&input);
        return -1;
    }
    ret = cfg_file_read_from_stream(cfg, &input, strict);
    my_fclose(&input);
    return ret;
}

static char const *cfg_file_remove_comment(
    char const *val, char const *val_end)
{
    char const *comment = my_strchr(val, '#');

    if (comment == NULL)
        return val_end;
    trim_str(&val, &comment);
    return comment;
}

static int cfg_file_parse_line(cfg_file_t *cfg, char const *key)
{
    char const *key_end = my_strchr(key, '=');
    char const *val = key_end;
    char const *val_end = my_strchr(key, '\0');
    char const *comment = my_strchr(key, '#');

    if (key_end == NULL)
        return 1;
    ++val;
    if (*trim_str(&key, &key_end) == '\0' || *trim_str(&val, &val_end) == '\0'
        || *val == '#' || (comment != NULL && comment < val))
        return 1;
    val_end = cfg_file_remove_comment(val, val_end);
    key = my_strndup(key, key_end - key);
    val = my_strndup(val, val_end - val);
    if (key == NULL || val == NULL) {
        free((void *)key);
        free((void *)val);
        return 1;
    }
    return my_hash_map_insert(&cfg->data, &key, &val) != MY_MAP_OK;
}

static int cfg_file_read_line(
    cfg_file_t *cfg, char const *line, size_t line_size, bool strict)
{
    if (line_size == 0 || (line_size == 1 && (*line == '\n' || *line == '\0')))
        return 0;
    while (my_isspace(*line))
        ++line;
    return *line != '#' && cfg_file_parse_line(cfg, line) && strict;
}

int cfg_file_read_from_stream(
    cfg_file_t *cfg, my_iostream_t *input, bool strict)
{
    char *line = NULL;
    int current_line = 1;
    size_t alloc_size = 0;
    ssize_t line_size;

    assert(cfg != NULL);
    assert(input != NULL);
    line_size = my_getline(&line, &alloc_size, input);
    while (line_size >= 0) {
        if (cfg_file_read_line(cfg, line, (size_t)line_size, strict)) {
            free(line);
            return current_line;
        }
        line_size = my_getline(&line, &alloc_size, input);
        ++current_line;
    }
    free(line);
    return my_feof(input) ? 0 : -current_line - 1;
}
