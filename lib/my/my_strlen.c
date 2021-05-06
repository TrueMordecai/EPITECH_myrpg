/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** count characters in a string
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length])
        length++;
    return (length);
}
