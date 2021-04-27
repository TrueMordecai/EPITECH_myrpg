/*
** EPITECH PROJECT, 2021
<<<<<<< HEAD
** rpg
** File description:
** my_vec_clear
=======
** LibMy - collections module
** File description:
** Flushes the elements of a vector
>>>>>>> bb5f890 (libmy: update to 0.3.8)
*/

#include "libmy/collections/vec.h"

MY_COLLECTIONS_API void my_vec_clear(my_vec_t *vec, void (*elem_free)(void *))
{
    assert(vec != NULL);
<<<<<<< HEAD
    if (elem_free) {
        size_t len = vec->length;
    
=======
    if (elem_free != NULL) {
        size_t len = vec->length;

>>>>>>> bb5f890 (libmy: update to 0.3.8)
        for (size_t i = 0; i < len; ++i)
            (*elem_free)(my_vec_get(vec, i));
    }
    vec->length = 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> bb5f890 (libmy: update to 0.3.8)
