/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - world
*/

#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <libmy/collections/vec.h>

#include "Physics/Utils/utils.h"
#include "Physics/DynamicTree/binary_tree.h"

struct pe_body_t;
struct pe_manifold_t;

typedef struct pe_world_t {
    pe_vec2f_t gravity;
    /// vector of elements of type 'pe_body_t *'
    /// bodies->data has the type 'pe_body_t **'
    /// Use @c PE_WORLD_BODY to get obtain a body.
    my_vec_t bodies;
    pe_bin_tree_t *tree;
} pe_world_t;

pe_world_t *pe_world_init(pe_vec2f_t gravity, \
unsigned short bodies_initial_capacity);
void pe_world_destroy(pe_world_t *world);

int pe_world_add_body(pe_world_t *world, pe_body_t *body);
void pe_world_update(pe_world_t *world, float dt);
void pe_world_handle_collisions_for_body(pe_world_t *world, pe_body_t *body);

/// Convenience macro for obtaning the i-th body from the body 'w'.
#define PE_WORLD_BODY(w, i) (MY_VEC_GET_ELEM(pe_body_t *, &w->bodies, i))

#endif /* !PHYSICS_WORLD_H */