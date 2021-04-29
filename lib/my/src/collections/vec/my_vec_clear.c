/*
** EPITECH PROJECT, 2021
<<<<<<< HEAD
<<<<<<< HEAD
** rpg
** File description:
** my_vec_clear
=======
** LibMy - collections module
** File description:
** Flushes the elements of a vector
>>>>>>> bb5f890 (libmy: update to 0.3.8)
=======
** LibMy - collections module
** File description:
** Flushes the elements of a vector
>>>>>>> origin/master
*/

#include "libmy/collections/vec.h"

MY_COLLECTIONS_API void my_vec_clear(my_vec_t *vec, void (*elem_free)(void *))
{
    assert(vec != NULL);
    if (elem_free != NULL) {
        size_t len = vec->length;

        for (size_t i = 0; i < len; ++i)
            (*elem_free)(my_vec_get(vec, i));
    }
    vec->length = 0;
}