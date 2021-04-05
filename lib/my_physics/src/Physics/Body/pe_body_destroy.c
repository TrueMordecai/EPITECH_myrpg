/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body destroy
*/

#include "Physics/physics.h"

void pe_body_destroy(pe_body_t *body)
{
    my_vec_free(&body->fixtures, (void (*))&pe_fixture_destroy);
    free(body);
}