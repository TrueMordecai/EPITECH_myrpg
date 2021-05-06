/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - tree raycast
*/

#include <libmy/collections/vec.h>

#include "Physics/Raycast/raycast.h"
#include "Physics/DynamicTree/binary_tree.h"

char pe_bin_tree_raycast(pe_bin_tree_t *tree, pe_vec2f_t p1, pe_vec2f_t p2)
{
    int index;
    my_vec_t stack;

    my_vec_init_capacity(&stack, tree->nb_nodes_set / 4, sizeof(int));
    my_vec_push(&stack, &tree->root_id);
    while (stack.length > 0) {
        my_vec_pop(&stack, &index);
        if (!pe_raycast_hit_aabb(&tree->nodes[index]->box, p1, p2))
            continue;
        if (tree->nodes[index]->is_leaf)
            return 1;
        else {
            my_vec_push(&stack, &tree->nodes[index]->child1_id);
            my_vec_push(&stack, &tree->nodes[index]->child2_id);
        }
    }
    my_vec_free(&stack, NULL);
    return 0;
}
