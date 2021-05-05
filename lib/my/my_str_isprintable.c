/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c
** File description:
** check if the string is printable
*/

int my_is_printable(char c)
{
    if (c < ' ' || c == 127)
        return (0);
    return (1);
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);
    while (str [i]) {
        if (!(my_is_printable(str[i])))
            return (0);
        i++;
    }
    return (1);
}
