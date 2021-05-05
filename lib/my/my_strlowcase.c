/*
** EPITECH PROJECT, 2020
** my_strlowcase.c
** File description:
** put in lower case every world of a stirng
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}
