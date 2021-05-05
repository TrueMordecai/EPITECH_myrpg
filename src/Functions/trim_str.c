/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Trims the string
*/

#include <assert.h>
#include <libmy/ascii/character.h>

#include "functions.h"

char *trim_str(char const **start, char const **end)
{
    assert(start != NULL);
    assert(end != NULL);
    if (*start > *end)
        my_swap_ptr((const void **)start, (const void **)end);
    while (*start < *end && my_isspace(**start))
        ++(*start);
    while (*end > *start && my_isspace(*(*end - 1)))
        --(*end);
    return (char *)*start;
}
