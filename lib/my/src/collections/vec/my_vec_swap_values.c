/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** swap two values in the vector
*/

#include <stdlib.h>
#include "libmy/collections.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_swap_values(
my_vec_t *vec, size_t index_1, size_t index_2)
{
    void *tmp = NULL;

    if (index_1 >= vec->length || index_2 >= vec->length)
        return MY_VEC_OUT_OF_BOUNDS;
    tmp = malloc(vec->elem_size);
    if (!tmp)
        return MY_VEC_ALLOC;
    my_memcpy(tmp, ((char *)vec->data) + vec->elem_size * index_1, vec->elem_size);
    my_memcpy(((char *)vec->data) + vec->elem_size * index_1, \
    ((char *)vec->data) + vec->elem_size * index_2, vec->elem_size);
    my_memcpy(((char *)vec->data) + vec->elem_size * index_2, tmp, vec->elem_size);
    free(tmp);
    return MY_VEC_OK;
}