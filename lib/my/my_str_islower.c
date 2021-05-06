/*
** EPITECH PROJECT, 2020
** my_str_islower.c
** File description:
** check if str is lower only
*/

int my_is_lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);
    while (str[i]) {
        if (!(my_is_lower(str[i])))
            return (0);
        i++;
    }
    return (1);
}
