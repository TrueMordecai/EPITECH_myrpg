/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - world destroy
*/

#include "Physics/physics.h"

// Is it normal that each body in world is not freed?
void pe_world_destroy(pe_world_t *world)
{
    my_vec_free(&world->bodies, NULL);
    pe_bin_tree_destroy(world->tree);
    free(world);
}
