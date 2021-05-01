/*
** EPITECH PROJECT, 2021
** My world
** File description:
** get random number
*/

#include <stdlib.h>
#include <limits.h>
#include "functions.h"

float get_rand(float min, float max)
{
    int num = rand();
    float res = (num / (float)INT_MAX) * (max - min) + min;
    return res;
}

int get_randi(int a, int b)
{
    int max = MAX(a, b);
    int min = MIN(a, b);
    return rand() % (max - min + 1) + min;
}