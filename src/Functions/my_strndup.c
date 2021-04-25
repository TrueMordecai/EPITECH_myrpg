/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** my_strndup
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strndup(char const *str, size_t n)
{
    char *new_str;
    size_t i = 0;

    if (str == NULL)
        return NULL;
    new_str = malloc(sizeof(char) * (n + 1));
    while (str[i] != 0 && i < n){
        new_str[i] = str[i];
        i++;
    }
    while (i < n + 1) {
        new_str[i] = 0;
        i++;
    }
    return new_str;
}