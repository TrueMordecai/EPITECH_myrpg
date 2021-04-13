/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** reverse memory
*/

#include <assert.h>
#include <stdint.h>

#include "libmy/memory/memory.h"

MY_MEMORY_API void *my_memrev(void *mem, size_t nmemb, size_t size)
{
    size_t half_len = nmemb / 2;

    assert(mem != NULL);
    for (size_t i = 0; i < half_len; i++) {
        void const **restrict a = ((char *)mem) + i * size;
        void const **restrict b = ((char *)mem) + (nmemb - (i + 1)) * size;

        *a = (void *)((uintptr_t)*a ^ (uintptr_t)*b);
        *b = (void *)((uintptr_t)*a ^ (uintptr_t)*b);
        *a = (void *)((uintptr_t)*a ^ (uintptr_t)*b);
    }
    return mem;
}