/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - set body angle
*/

#include "Physics/physics.h"

void pe_body_set_angle(pe_body_t *body, float rad_angle)
{
    body->angle = rad_angle;
    for (size_t i = 0; i < body->fixtures.length; i++) {
        if (PE_BODY_FIXTURE(body, i)->shape.shape_type == POLYGON)
            pe_mat22_init_from_angle(
                &PE_BODY_FIXTURE(body, i)->shape.mat_rot, rad_angle);
    }
}

void pe_body_rotate(pe_body_t *body, float rad_angle)
{
    pe_body_set_angle(body, body->angle + rad_angle);
    pe_body_compute_aabb(body);
}
