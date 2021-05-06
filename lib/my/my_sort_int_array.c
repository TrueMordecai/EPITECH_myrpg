/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** tri de tableau
*/

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int temp;

    while (i < size) {
        if (array[i] > array[i + 1]) {
            temp = array[i + 1];
            array[i + 1] = array[i];
            array[i] = temp;
            i = 0;
        }
        else
            i++;
    }
}
