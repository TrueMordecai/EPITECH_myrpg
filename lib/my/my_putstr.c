/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** print a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
