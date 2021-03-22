/*
** EPITECH PROJECT, 2021
** My world
** File description:
** get random number
*/

#include <stdlib.h>
#include <limits.h>
#include "functions.h"
#include "My/my_display.h"

float get_rand(float min, float max)
{
    int num = rand();
    float res = (num / (float)INT_MAX) * (max - min) + min;
    return res;
}