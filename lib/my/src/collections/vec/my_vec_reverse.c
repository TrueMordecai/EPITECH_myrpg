/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Reverse the vec elements
*/

#include <stdlib.h>
#include "libmy/collections.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_reverse(my_vec_t *vec)
{
    my_vec_err_t error = MY_VEC_OK;

    for (size_t i = 0; !error && i < vec->length / 2; i++)
        error = my_vec_swap_values(vec, i, vec->length - (i + 1));
    return error;
}