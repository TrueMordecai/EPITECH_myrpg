/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** concatenate n char of two strings
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[j])
        j++;
    while (i <= nb && src[i]) {
        dest[j] = src[i];
        j++;
        i++;
    }
    dest[j] = '\0';
    return (dest);
}
