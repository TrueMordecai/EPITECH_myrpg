/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** prints char
*/

#include <unistd.h>

void my_putchar(char const c)
{
    write(1, &c, 1);
}
