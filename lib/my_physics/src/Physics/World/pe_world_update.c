/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update world
*/

#include "Physics/physics.h"

static void update_world_body(pe_world_t *world, pe_body_t *body, float dt)
{
    pe_body_add_force(body, VEC2F_MUL1(world->gravity, body->mass.mass));
    pe_body_integrate_forces(body, dt);
    pe_body_update(body, dt);
    pe_aabb_copy(&world->tree->nodes[body->id]->box, &body->aabb);
    pe_body_clear_forces(body, 1, 1, 1);
}

void pe_world_update(pe_world_t *world, float dt)
{
    float dt_sec = (dt / 1000.f);
    size_t body_count = world->bodies.length;

    for (size_t i = 0; i < body_count; i++) {
        if (PE_WORLD_BODY(world, i)->body_type != STATIC
            && PE_WORLD_BODY(world, i)->is_awake)
            update_world_body(world, PE_WORLD_BODY(world, i), dt_sec);
    }
    for (size_t i = 0; i < body_count; i++) {
        if (PE_WORLD_BODY(world, i)->body_type != STATIC)
            pe_world_handle_collisions_for_body(
                world, PE_WORLD_BODY(world, i));
    }
    for (size_t i = 0; i < body_count; i++) {
        if (PE_WORLD_BODY(world, i)->body_type != STATIC
            && PE_WORLD_BODY(world, i)->is_awake)
            pe_body_try_sleep(PE_WORLD_BODY(world, i), dt_sec);
    }
    pe_bin_tree_update(world->tree);
}
