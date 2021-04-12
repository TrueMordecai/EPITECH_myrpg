/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body destroy
*/

#include "Physics/physics.h"

static void pe_body_destroy_fixture(void *fixture)
{
    pe_shape_reset(&(*(pe_fixture_t **)fixture)->shape);
}

void pe_body_destroy(pe_body_t *body)
{
    my_vec_free(&body->fixtures, &pe_body_destroy_fixture);
    free(body);
}
