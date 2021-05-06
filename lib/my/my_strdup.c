/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** string duplicate
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i]) {
        my_strcpy(dest, src);
        i++;
    }
    return (dest);
}
