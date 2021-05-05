/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** fight_pathfinding
*/

#include <libmy/collections/vec.h>
#include <libmy/memory/memory.h>
#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"

int get_next_pos(fight_t *fight, int current, int dir);
int node_compare(node_t *na, node_t *nb);
void sort_nodes(my_vec_t *nodes);
node_t **init_nodes(fight_t *fight, int start, int end);
int get_heuristic_cost(fight_t *fight, int pos_a, int pos_b);

static my_vec_t *resolve_path(node_t *end)
{
    my_vec_t *path = NULL;
    node_t *current = end;
    int size = 0;

    if (!current)
        return path;
    while (current) {
        size++;
        current = current->parent;
    }
    current = end;
    path = malloc(sizeof(my_vec_t));
    my_vec_init(path, sizeof(int));
    my_vec_set_capacity(path, size, NULL);
    while (current) {
        my_vec_push(path, &current->pos);
        current = current->parent;
    }
    my_memrev(path->data, path->length, sizeof(int));
    return path;
}

static void handle_dir(
    fight_t *fight, sfVector3f dir_cur_end, node_t **nodes, my_vec_t *opened)
{
    node_t *current = nodes[(int)dir_cur_end.y];
    node_t *neighbour;
    int cost;
    int next_pos = get_next_pos(fight, current->pos, dir_cur_end.x);

    if (next_pos == INEXISTING)
        return;
    neighbour = nodes[next_pos];
    if (!neighbour->visited && !neighbour->wall)
        my_vec_push(opened, &neighbour);
    cost = current->l_cost
        + get_heuristic_cost(fight, current->pos, neighbour->pos);
    if (cost < neighbour->l_cost) {
        neighbour->parent = current;
        neighbour->l_cost = cost;
        neighbour->g_cost = neighbour->l_cost
            + get_heuristic_cost(fight, neighbour->pos, dir_cur_end.z);
    }
}

static my_vec_t *end_algo(
    fight_t *fight, my_vec_t *opened, node_t *current, node_t **nodes)
{
    my_vec_t *path = NULL;

    my_vec_free(opened, NULL);
    if ((current != NULL))
        path = resolve_path(current);
    for (int x = 0; x < fight->size.x; x++) {
        for (int y = 0; y < fight->size.y; y++) {
            free(nodes[x + y * fight->size.x]);
        }
    }
    free(nodes);
    return path;
}

my_vec_t *fight_get_path_2(
    fight_t *fight, node_t **nodes, my_vec_t opened, int to)
{
    node_t *current;

    while (opened.length) {
        sort_nodes(&opened);
        while (opened.length
            && MY_VEC_GET_ELEM(node_t *, &opened, opened.length - 1)->visited)
            my_vec_pop(&opened, NULL);
        if (!opened.length)
            break;
        current = my_vec_get(&opened, 0);
        my_vec_pop(&opened, &current);
        if (current->pos == to)
            return end_algo(fight, &opened, current, nodes);
        current->visited = 1;
        for (int dir = 0; dir < 4; dir++)
            handle_dir(
                fight, (sfVector3f){dir, current->pos, to}, nodes, &opened);
    }
    return end_algo(fight, &opened, NULL, nodes);
}

my_vec_t *fight_get_path(fight_t *fight, int from, int to)
{
    node_t **nodes = init_nodes(fight, from, to);
    node_t *current = nodes[from];
    my_vec_t opened;

    my_vec_init(&opened, sizeof(node_t *));
    my_vec_push(&opened, &current);
    return fight_get_path_2(fight, nodes, opened, to);
}
