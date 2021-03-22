/*
** EPITECH PROJECT, 2020
** GameEngine
** File description:
** asset manager functions
*/

#include "functions.h"
#include "My/my_strings.h"

int my_map_strcmp(char *s1, size_t s2)
{
    size_t str_addr = *((size_t *)s1);

    return (my_strcmp((const char *)str_addr, (const char *)s2) == 0);
}

int my_map_intcmp(char *v1, size_t v2)
{
    int i1 = *((int *)v1);

    for (int i = 0; i < sizeof(int); i++){
        if (*((char *)(&i1) + i) != *((char *)(&v2) + i))
            return 0;
    }
    return 1;
}

int my_map_charcmp(char *v1, size_t v2)
{
    return (*v1 == *((char *)(&v2)));
}