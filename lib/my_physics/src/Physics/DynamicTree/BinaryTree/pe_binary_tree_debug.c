/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - display binary tree
*/

#include <libmy/collections/vec.h>

#include "Physics/physics.h"

void pe_bin_tree_display(pe_bin_tree_t *tree)
{
    int index = tree->root_id;
    my_vec_t queue;

    my_vec_init_capacity(&queue, 10, sizeof(int));
    my_vec_push(&queue, &tree->root_id);
    while (queue.length > 0) {
        index = MY_VEC_GET_ELEM(int, &queue, 0);
        printf("%4d->%-4d", tree->nodes[index]->parent_id, index);
        if (!tree->nodes[index]->is_leaf) {
            my_vec_push(&queue, &tree->nodes[index]->child1_id);
            my_vec_push(&queue, &tree->nodes[index]->child2_id);
        }
        my_vec_remove(&queue, NULL, 0);
    }
    my_vec_free(&queue, NULL);
}