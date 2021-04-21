/*
** EPITECH PROJECT, 2020
** my_strupcase.c
** File description:
** put every letter of every word in uppercase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] <= 'z' && str[i] >= 'a')
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
