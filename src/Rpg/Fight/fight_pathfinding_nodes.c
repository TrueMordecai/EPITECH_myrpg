/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** fight_pathfinding_2
*/

#include <libmy/collections/vec.h>

#include "Rpg/Fight/fight.h"

node_t **init_nodes(fight_t *fight, int start, int end)
{
    node_t **nodes = malloc(sizeof(node_t *) * fight->size.x * fight->size.y);
    node_t *node;

    for (int x = 0; x < fight->size.x; x++) {
        for (int y = 0; y < fight->size.y; y++) {
            node = malloc(sizeof(node_t));
            node->g_cost = __SHRT_MAX__;
            node->l_cost = __SHRT_MAX__;
            node->parent = NULL;
            node->visited = 0;
            node->wall = !cell_is_empty(&fight->grid[x + y * fight->size.x]);
            node->pos = x + y * fight->size.x;
            nodes[x + y * fight->size.x] = node;
        }
    }
    nodes[start]->l_cost = 0;
    nodes[start]->g_cost = get_heuristic_cost(fight, 0, end);
    return nodes;
}

int node_compare(node_t *na, node_t *nb)
{
    if (na->g_cost == nb->g_cost)
        return na->l_cost > nb->l_cost;
    return na->g_cost > nb->g_cost;
}

void sort_nodes(my_vec_t *nodes)
{
    node_t *node;
    int j;

    for (size_t i = 1; i < nodes->length; i++) {
        node = MY_VEC_GET_ELEM(node_t *, nodes, i);
        j = i - 1;
        while (
            j >= 0 && node_compare(node, MY_VEC_GET_ELEM(node_t *, nodes, j))) {
            my_vec_change_value(nodes, my_vec_get(nodes, j), j + 1);
            j = j - 1;
        }
        my_vec_change_value(nodes, &node, j + 1);
    }
}
