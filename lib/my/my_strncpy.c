/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** string copy of n char
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0')
            return (dest);
    }
    return (dest);
}
