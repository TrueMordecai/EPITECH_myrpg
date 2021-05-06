/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** Compare deux chaines de characteres
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s2[i] && s1[i]) && (s2[i] == s1[i])) {
        i++;
    }
    return (s1[i] - s2[i]);
}
