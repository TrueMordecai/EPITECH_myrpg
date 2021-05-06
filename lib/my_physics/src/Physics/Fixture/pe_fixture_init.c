/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - fixture init
*/

#include <assert.h>
#include <libmy/memory/alloc.h>

#include "Physics/physics.h"

pe_fixture_t *pe_fixture_init(void)
{
    pe_fixture_t *fixture = my_calloc(1, sizeof(pe_fixture_t));

    assert(fixture != NULL);
    pe_shape_init_default(&fixture->shape);
    fixture->static_friction = 0.5;
    fixture->dynamic_friction = 0.3;
    fixture->restitution = 0.5;
    fixture->density = 1;
    pe_filter_init(&fixture->collision_filter);
    pe_fixture_update_mass_datas(fixture);
    return fixture;
}
