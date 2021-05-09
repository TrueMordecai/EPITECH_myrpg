/*
** EPITECH PROJECT, 2021
** MyRPG - Functions
** File description:
** Parsing utilities
*/

#include <libmy/ascii.h>
#include "functions.h"

long get_number_adv(char const *str, size_t *i, bool is_signed, bool only_num)
{
    long res = 0;
    size_t index = (i) ? *i : 0;
    int neg = (is_signed && str[index] == '-');

    if (neg)
        index++;
    while (str[index] != 0 && (!only_num || my_isdigit(str[index]))) {
        res *= 10;
        res += str[index] - '0';
        index++;
    }
    if (neg)
        res *= -1;
    if (i)
        *i = index;
    return res;
}

long get_number_pass(char const *str, size_t *i)
{
    long res = get_number_adv(str, i, true, true);

    if (i && str[*i] != 0)
        (*i)++;
    return res;
}
