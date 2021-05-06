/*
** EPITECH PROJECT, 2020
** my_strcapitalize.c
** File description:
** Capitalize every first letter of a world
*/

int is_ok(char c)
{
    if (c == '+' || c == '-' || c == ' ')
        return (1);
    return (0);
}

int is_lower_case(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] = str[i] + 32;
        i++;
    }
    i = 0;
    while (str[i]) {
        if (i == 0 && is_lower_case(str[i]))
            str[i] = str[i] - 32;
        if (i > 0 && is_ok(str[i - 1]))
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
