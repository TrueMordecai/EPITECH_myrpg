/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - fixture destroy
*/

#include <stdlib.h>
#include "Physics/Fixture/fixture.h"

void pe_fixture_destroy(pe_fixture_t *fixture)
{
    pe_shape_reset(&fixture->shape);
    free(fixture);
}
