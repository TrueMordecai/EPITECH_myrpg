/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_compute_move
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"
#include "functions.h"

static sfVector2i get_allies_counts(entity_t *entity, int max_dist)
{
    fight_t *fight = entity->fight;
    sfVector2i nb_allies = {0, 0};

    for (int i = 0; i < fight->nb_entities; i++) {
        if (fight->entities[i]->type == ENNEMY)
            continue;
        nb_allies.x++;
        nb_allies.y += get_heuristic_cost(fight, entity->pos, \
        fight->entities[i]->pos) <= max_dist;
    }
    return nb_allies;
}

static int get_allies(fight_t *fight, entity_t *entity, \
int **allies, int *nb_allies)
{
    int po = 5;
    int max_dist = po + entity->stats->current_pm;
    int ally_id = 0;
    sfVector2i counts = get_allies_counts(entity, max_dist);

    if (counts.x == 0)
        return 0;
    *allies = malloc(sizeof(int) * ((counts.y) ? counts.y : counts.x));
    for (int i = 0; i < fight->nb_entities; i++) {
        if (fight->entities[i]->type == ENNEMY)
            continue;
        if (!counts.y || get_heuristic_cost(fight, entity->pos, \
            fight->entities[i]->pos) <= max_dist)
            *allies[ally_id++] = i;
    }
    *nb_allies = ally_id;
    return counts.y;
}

static int *get_nearest_side_path(fight_t *fight, int from, \
int to, int *min_len)
{
    sfVector2i vec_to = fight_pos_to_vec(fight, to, 0);
    sfVector2i test_pos;
    int *tmp;
    int len;
    int *path = NULL;

    for (int i = 0; i < 4; i++) {
        test_pos = vec_to;
        if (i % 2 == 0)
            test_pos.x += ((i) ? 1 : -1);
        else
            test_pos.y += ((i == 3) ? 1 : -1);
        tmp = fight_get_path(fight, from, fight_vec_to_pos(fight, test_pos));
        len = 0;
        for (int j = 0; tmp && tmp[j] != END_ARRAY; j++)
            len++;
        if (tmp && len < *min_len) {
            *min_len = len;
            path = tmp;
        } else
            free(tmp);
    }
    return path;
}

static void move_forward(entity_t *entity, int *allies, int nb_allies)
{
    int *tmp;
    int *path = NULL;
    int min_len = INT32_MAX;

    for (int i = 0; i < nb_allies; i++) {
        tmp = get_nearest_side_path(entity->fight, entity->pos, \
        entity->fight->entities[allies[i]]->pos, &min_len);
        if (tmp)
            path = tmp;
    }
    my_printf("Path %p\n", path);
    free(entity->move_path);
    entity->move_path = path;
    entity_move(entity);
    free(allies);
}

static void union_sights(int **sight, int *sight_tmp)
{
    if (!(*sight)) {
        *sight = sight_tmp;
        return;
    }
    for (int i = 0; (*sight)[i] != END_ARRAY; i++) {
        if ((*sight)[i] != 0 && sight_tmp[i] == 0)
            (*sight)[i] = 0;
    }
    free(sight_tmp);
}

int get_allies_sum_dist(entity_t *entity, int nb_allies, int *allies, int pos)
{
    int *tmp = NULL;
    int dist_sum = 0;

    for (int i = 0; i < nb_allies; i++) {
        tmp = fight_get_path(entity->fight, \
        entity->fight->entities[allies[i]]->pos, pos);
        if (!tmp)
            continue;
        for (int j = 0; tmp[j] != END_ARRAY; j++)
            dist_sum++;
        free(tmp);
    }
    return dist_sum;
}

void flee_2(entity_t *entity, int nb_allies, \
int *allies, int max_dist, int *sight)
{
    int nb_cells = 0;
    int dist;
    int max = INT32_MIN;
    int choice = 0;

    for (int i = 0; sight[i] != END_ARRAY; i++) {
        if ((sight[i] == 0 && max_dist >= 0) || \
            entity->move_possibilities[i] == INEXISTING || \
            !cell_is_empty(&entity->fight->grid[entity->move_possibilities[i]]))
            continue;
        dist = get_heuristic_cost(entity->fight, \
        entity->pos, entity->move_possibilities[i]);
        if (dist < max_dist)
            continue;
        dist = get_allies_sum_dist(entity, nb_allies, \
        allies, entity->move_possibilities[i]);
        if (dist > max) {
            max = dist;
            nb_cells = 0;
        }
        nb_cells += (dist == max);
    }
    choice = get_randi(0, nb_cells - 1);
    for (int i = 0; sight[i] != END_ARRAY; i++) {
        if ((sight[i] == 0 && max_dist >= 0) || \
            entity->move_possibilities[i] == INEXISTING || \
            !cell_is_empty(&entity->fight->grid[entity->move_possibilities[i]]))
            continue;
        dist = get_heuristic_cost(entity->fight, entity->pos, \
        entity->move_possibilities[i]);
        if (dist < max_dist)
            continue;
        dist = get_allies_sum_dist(entity, nb_allies, allies, \
        entity->move_possibilities[i]);
        if (dist < max)
            continue;
        if (!choice) {
            free(entity->move_path);
            entity->fight->grid[entity->pos].entity = entity;
            entity->move_path = fight_get_path(entity->fight, \
            entity->pos, entity->move_possibilities[i]);
            entity_move(entity);
            break;
        }
        choice--;
    }
}

void flee_away(entity_t *entity, int nb_allies, int *allies)
{
    int ally_po = 5;
    fight_t *fight = entity->fight;
    int *sight = NULL;
    int *sight_tmp = NULL;
    entity_t *ally;
    int max_dist = INT32_MIN;
    int nb_max_dist = 0;
    int dist;

    entity->fight->grid[entity->pos].entity = NULL;
    for (int i = 0; i < nb_allies; i++) {
        ally = fight->entities[allies[i]];
        sight_tmp = fight_get_sight(fight, (sfVector2i)\
        {ally->pos, entity->stats->current_pm}, \
        (sfVector2i){ally_po, 0}, &entity->move_possibilities);
        union_sights(&sight, sight_tmp);
    }
    for (int i = 0; sight[i] != END_ARRAY; i++) {
        if (sight[i] == 0 || entity->move_possibilities[i] == INEXISTING || \
            !cell_is_empty(&entity->fight->grid[entity->move_possibilities[i]]))
            continue;
        dist = get_heuristic_cost(entity->fight, entity->pos, \
        entity->move_possibilities[i]);
        if (dist > max_dist) {
            max_dist = dist;
            nb_max_dist = 0;
        }
        nb_max_dist += (dist == max_dist);
    }
    flee_2(entity, nb_allies, allies, max_dist, sight);
    free(sight);
}

static void move_to_reachable_sights(entity_t *entity, int *sight, \
int nb_allies, int *allies)
{
    int *tmp;
    int *path = NULL;
    int len;
    int min_len = INT32_MAX;

    for (int i = 0; sight[i] != END_ARRAY; i++) {
        if (sight[i])
            continue;
        tmp = fight_get_path(entity->fight, entity->pos, \
        entity->move_possibilities[i]);
        len = 0;
        for (int j = 0; tmp && tmp[j] != END_ARRAY; j++)
            len++;
        if (tmp && len < min_len) {
            min_len = len;
            path = tmp;
        } else
            free(tmp);
    }
    free(entity->move_path);
    entity->move_path = path;
    entity_move(entity);
    //attack
    flee_away(entity, nb_allies, allies);
}

static void get_reachable_sights(entity_t *entity, int *allies, int nb_allies)
{
    int po = 5;
    fight_t *fight = entity->fight;
    int *sight = NULL;
    int *sight_tmp = NULL;
    int sight_pos = 0;

    entity_update_move_possibilities(entity);
    for (int i = 0; i < nb_allies; i++) {
        sight_tmp = fight_get_sight(fight, (sfVector2i)\
        {fight->entities[allies[i]]->pos, entity->stats->current_pm}, \
        (sfVector2i){po, 0}, &entity->move_possibilities);
        union_sights(&sight, sight_tmp);
    }
    for (int i = 0; sight[i] != END_ARRAY; i++)
        sight_pos += (sight[i] == 0);
    if (!sight_pos) {
        my_printf("No ally reachable by moving, move forward\n");
        move_forward(entity, allies, nb_allies);
    } else {
        my_printf("Ally reachable by moving, attack\n");
        move_to_reachable_sights(entity, sight, nb_allies, allies);
        free(allies);
    }
    free(sight);
}

void entity_compute_move(entity_t *entity)
{
    fight_t *fight = entity->fight;
    int nb_allies = 0;
    int *allies = NULL;

    if (entity->type != ENNEMY)
        return;
    if (!get_allies(fight, entity, &allies, &nb_allies)) {
        my_printf("Allies too far, move forward\n");
        move_forward(entity, allies, nb_allies);
        return;
    }
    get_reachable_sights(entity, allies, nb_allies);
}