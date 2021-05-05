/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - body destroy
*/

#include <stdlib.h>
#include "Physics/physics.h"

static void pe_body_destroy_fixture(void *fixture)
{
    pe_shape_reset(&(*(pe_fixture_t **)fixture)->shape);
    free(*(pe_fixture_t **)fixture);
}

void pe_body_destroy(pe_body_t *body)
{
    my_vec_free(&body->fixtures, &pe_body_destroy_fixture);
    free(body);
}
