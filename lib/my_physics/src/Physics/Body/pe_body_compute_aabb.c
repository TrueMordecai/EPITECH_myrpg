/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body compute aabb
*/

#include "Physics/physics.h"

void pe_body_compute_aabb(pe_body_t *body)
{
    pe_aabb_init(&body->aabb, body->pos, body->pos, 1);
    for (size_t i = 0; i < body->fixtures.length; i++) {
        pe_aabb_union_shape(&body->aabb, &body->aabb,
            &PE_BODY_FIXTURE(body, i)->shape, body->pos);
    }
}
