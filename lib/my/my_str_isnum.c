/*
** EPITECH PROJECT, 2020
** my_str_isnum.c
** File description:
** check if its digits only
*/

int my_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);
    while (str[i]) {
        if (!(my_is_num(str[i])))
            return (0);
        i++;
    }
    return (1);
}
