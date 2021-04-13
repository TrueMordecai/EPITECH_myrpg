/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - world init
*/

#include "Physics/physics.h"

pe_world_t *pe_world_init(pe_vec2f_t gravity, \
unsigned short bodies_initial_capacity)
{
    pe_world_t *world = malloc(sizeof(pe_world_t));

    if (world == NULL)
        return NULL;
    world->gravity = gravity;
    my_vec_init_capacity(
        &world->bodies, (size_t)bodies_initial_capacity, sizeof(pe_body_t *));
    world->tree = pe_bin_tree_init(bodies_initial_capacity);
    return world;
}