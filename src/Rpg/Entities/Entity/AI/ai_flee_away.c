/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** ai_flee_away
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"
#include "functions.h"

int *init_sight(entity_t *entity, my_vec_t *allies, int ally_po);
void free_tmp_path(my_vec_t *path);

int get_allies_sum_dist(entity_t *entity, my_vec_t *allies, int pos)
{
    my_vec_t *tmp = NULL;
    int dist_sum = 0;

    for (size_t i = 0; i < allies->length; i++) {
        tmp = fight_get_path(
            entity->fight, MY_VEC_GET_ELEM(entity_t *, allies, i)->pos, pos);
        if (!tmp)
            continue;
        dist_sum += tmp->length;
        my_vec_free(tmp, NULL);
        free(tmp);
    }
    return dist_sum;
}

static my_vec_t *fill_choices(
    entity_t *entity, my_vec_t *allies, int max_dist, int *sight)
{
    int dist;
    int max = INT32_MIN;
    int *p = entity->move_possibilities;
    my_vec_t *choices = malloc(sizeof(my_vec_t));

    my_vec_init(choices, sizeof(int));
    for (int i = 0; sight[i] != END_ARRAY; i++) {
        if ((sight[i] == 0 && max_dist >= 0) || p[i] == INEXISTING
            || !cell_is_empty(&entity->fight->grid[p[i]])
            || get_heuristic_cost(entity->fight, entity->pos, p[i]) < max_dist
            || get_allies_sum_dist(entity, allies, p[i]) < max)
            continue;
        dist = get_allies_sum_dist(entity, allies, p[i]);
        if (dist > max) {
            max = dist;
            my_vec_pop_multiple(choices, NULL, choices->length);
        }
        my_vec_push(choices, &p[i]);
    }
    return choices;
}

void flee_2(entity_t *entity, my_vec_t *allies, int max_dist, int *sight)
{
    my_vec_t *choices = fill_choices(entity, allies, max_dist, sight);

    free_tmp_path(entity->move_path);
    entity->fight->grid[entity->pos].entity = entity;
    entity->move_path = fight_get_path(entity->fight, entity->pos,
        MY_VEC_GET_ELEM(int, choices, get_randi(0, choices->length - 1)));
    my_vec_free(choices, NULL);
    free(choices);
    entity_move(entity, 0);
}

void flee_away(entity_t *entity, my_vec_t *allies)
{
    int *sight = init_sight(entity, allies, 1);
    int max_dist = INT32_MIN;
    int nb_max_dist = 0;
    int dist;

    for (int i = 0; sight[i] != END_ARRAY; i++) {
        if (sight[i] == 0 || entity->move_possibilities[i] == INEXISTING
            || !cell_is_empty(
                &entity->fight->grid[entity->move_possibilities[i]]))
            continue;
        dist = get_heuristic_cost(
            entity->fight, entity->pos, entity->move_possibilities[i]);
        if (dist > max_dist) {
            max_dist = dist;
            nb_max_dist = 0;
        }
        nb_max_dist += (dist == max_dist);
    }
    flee_2(entity, allies, max_dist, sight);
    free(sight);
}
