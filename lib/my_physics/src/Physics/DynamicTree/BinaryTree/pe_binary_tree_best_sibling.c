/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - binary tree pick best sibling
*/

#include <libmy/collections/vec.h>
#include <stdio.h>

#include "Physics/DynamicTree/binary_tree.h"

static float get_direct_cost(pe_tree_node_t *node, pe_tree_node_t *new_node)
{
    pe_aabb_t buffer;

    return pe_aabb_area(pe_aabb_union(&buffer, &node->box, &new_node->box));
}

static float get_inherited_cost(pe_bin_tree_t *tree, pe_tree_node_t *node,
    pe_tree_node_t *new_node, int include_node)
{
    float area = pe_aabb_area(&node->box);
    float inherited =
        (include_node) ? get_direct_cost(node, new_node) - area : 0;
    pe_tree_node_t *current = node;

    while (current->parent_id != -1) {
        current = tree->nodes[current->parent_id];
        area = pe_aabb_area(&current->box);
        inherited += get_direct_cost(current, new_node) - area;
    }
    return inherited;
}

static void push_childs(pe_bin_tree_t *tree, my_vec_t *queue, float *costs,
    pe_tree_node_t *new_node)
{
    int head = MY_VEC_GET_ELEM(int, queue, 0);

    costs[1] = costs[2]
        + (costs[1] - (costs[2] + pe_aabb_area(&tree->nodes[head]->box)))
        + pe_aabb_area(&new_node->box);
    if (costs[1] < costs[0] && !tree->nodes[head]->is_leaf) {
        my_vec_push(queue, &tree->nodes[head]->child1_id);
        my_vec_push(queue, &tree->nodes[head]->child2_id);
    }
}

/*
** Costs :
** 0 : best
** 1 : current
** 2 : inherited
*/
int pe_bin_tree_find_best_sibling(
    pe_bin_tree_t *tree, pe_tree_node_t *new_node)
{
    float costs[3] = {get_direct_cost(tree->nodes[tree->root_id], new_node)};
    int best = tree->root_id;
    my_vec_t queue;
    int head;

    my_vec_init_capacity(&queue, 5, sizeof(int));
    my_vec_push(&queue, &best);
    while (queue.length > 0) {
        head = MY_VEC_GET_ELEM(int, &queue, 0);
        costs[2] = get_inherited_cost(tree, tree->nodes[head], new_node, 0);
        costs[1] = costs[2] + get_direct_cost(tree->nodes[head], new_node);
        if (costs[1] < costs[0]) {
            costs[0] = costs[1];
            best = head;
            push_childs(tree, &queue, costs, new_node);
        }
        my_vec_remove(&queue, NULL, 0);
    }
    my_vec_free(&queue, NULL);
    return best;
}
