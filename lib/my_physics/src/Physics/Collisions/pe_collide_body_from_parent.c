/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - detect collisions
*/

#include <libmy/collections.h>

#include "Physics/physics.h"

static void collide_leaf(pe_bin_tree_t *tree, int node_index, pe_body_t *body)
{
    if (tree->nodes[node_index]->tested == 0 && node_index != body->id
        && pe_collide_aabbs(&tree->nodes[node_index]->box, &body->aabb)) {
        pe_collide_bodies(tree->nodes[node_index]->body, body);
    }
}

void pe_collide_body_from_parent(
    pe_bin_tree_t *tree, int parent_box_id, pe_body_t *body)
{
    my_vec_t stack;
    int index;

    my_vec_init_capacity(&stack, tree->nb_nodes_set / 4, sizeof(int));
    my_vec_push(&stack, &parent_box_id);
    while (stack.length > 0) {
        my_vec_pop(&stack, &index);
        if (tree->nodes[index]->is_leaf) {
            collide_leaf(tree, index, body);
        } else {
            my_vec_push(&stack, &tree->nodes[index]->child1_id);
            my_vec_push(&stack, &tree->nodes[index]->child2_id);
        }
    }
    my_vec_free(&stack, NULL);
}
