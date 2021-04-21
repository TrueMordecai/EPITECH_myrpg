/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** swap integers
*/

void my_swap(int *a, int *b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}
