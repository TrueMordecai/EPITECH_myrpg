/*
** EPITECH PROJECT, 2020
** my_str_isalpha.c
** File description:
** test if a string is alpha only
*/

int my_is_letter(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);

    while (str[i]) {
        if (!(my_is_letter(str[i])))
            return (0);
        i++;
    }
    return (1);
}
