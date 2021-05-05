/*
** EPITECH PROJECT, 2020
** my_isalpha.c
** File description:
** is a letter
*/

int my_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}

int my_str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalpha(str[i]) == 0) {
            return (0);
        }
    }
    return (1);
}