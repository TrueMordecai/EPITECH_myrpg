/*
** EPITECH PROJECT, 2020
** my_str_isupper.c
** File description:
** if uppercase only
*/

int my_isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (!(my_isupper(str[i])))
            return (1);
        i++;
    }
    return (0);
}
