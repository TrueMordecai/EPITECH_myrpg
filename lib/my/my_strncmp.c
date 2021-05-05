/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** compare n charactere de deux fonctions
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return (0);
    while (s1[i] && s2[i] && i < n - 1 && s2[i] == s1[i])
        i++;
    return (s1[i] - s2[i]);
}
