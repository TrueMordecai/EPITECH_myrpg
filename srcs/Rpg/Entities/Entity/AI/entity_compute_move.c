/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_compute_move
*/

#include "Fight/fight.h"

static sfVector2i get_allies_counts(entity_t *entity, int max_dist)
{
    fight_t *fight = entity->fight;
    int po = 5;
    sfVector2i nb_allies = {0, 0};

    for (int i = 0; i < fight->nb_entities; i++) {
        if (fight->entities[i]->type == ENNEMY)
            continue;
        nb_allies.x++;
        nb_allies.y += get_heuristic_cost(fight, entity->pos, fight->entities[i]->pos) < max_dist;
    }
    return nb_allies;
}

static int get_allies(fight_t *fight, entity_t *entity, int **allies, int *nb_allies)
{
    int po = 5;
    int max_dist = po + entity->stats->current_pm;
    int ally_id = 0;
    sfVector2i counts = get_allies_counts(entity, max_dist);

    if (counts.x == 0)
        return 0;
    *allies = malloc(sizeof(int) * (1 + (counts.y) ? counts.y : counts.x));
    for (int i = 0; i < fight->nb_entities; i++) {
        if (fight->entities[i]->type == ENNEMY)
            continue;
        if (!counts.y || get_heuristic_cost(fight, entity->pos, fight->entities[i]->pos) < max_dist)
            *allies[ally_id++] = i;
    }
    *allies[ally_id] = -1;
    *nb_allies = ally_id;
    return counts.x;
}

static void move_forward(entity_t *entity, int *allies, int nb_allies)
{
    int *paths[nb_allies];
    int *tmp;
    int *path = NULL;
    int len;
    int min_len = INT32_MAX;
    int min_id = -1;

    for (int i = 0; i < nb_allies; i++) {
        tmp = fight_get_path(entity->fight, entity->pos, entity->fight->entities[allies[i]]->pos);
        len = 0;
        for (int j = 0; tmp && tmp[j] != END_ARRAY; j++);
            len++;
        if (tmp && len < min_len) {
            min_len = len;
            min_id = i;
            path = tmp;
        } else
            free(tmp);
    }
    entity->move_path = path;
    entity_move(entity);
    free(allies);
}

int attack_reachables(entity_t *entity, int *allies, int nb_allies)
{
    fight_t *fight = entity->fight;
    int po = 5;
    int *range = NULL;
    int *sight = fight_get_sight(entity->fight, (sfVector2i){entity->pos, po}, 0, &range);
    entity_t *cell_entity;

    for (int i = 0; range[i] != END_ARRAY; i++) {
        if (sight[i])
            continue;
        cell_entity = fight->grid[range[i]].entity;
        if (!cell_entity || cell_entity->team == ENNEMIES)
            continue;
        
    }
}

void entity_compute_move(entity_t *entity)
{
    fight_t *fight = entity->fight;
    int nb_allies;
    int *allies;

    if (entity->type != ENNEMY)
        return;
    if (!get_allies(fight, entity, &allies, &nb_allies)) {
        move_forward(entity, allies, nb_allies);
        return;
    }
}