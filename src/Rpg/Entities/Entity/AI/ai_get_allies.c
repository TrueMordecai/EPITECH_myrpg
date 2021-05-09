/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** ai_get_allies
*/

#include "Rpg/Fight/fight.h"

static sfVector2i get_allies_counts(entity_t *entity, int max_dist)
{
    fight_t *fight = entity->fight;
    sfVector2i nb_allies = {0, 0};

    for (int i = 0; i < fight->nb_entities; i++) {
        if (fight->entities[i]->team == ENNEMIES
            || fight->entities[i]->alive != 1)
            continue;
        nb_allies.x++;
        nb_allies.y +=
            get_heuristic_cost(fight, entity->pos, fight->entities[i]->pos)
            <= max_dist;
    }
    return nb_allies;
}

int get_allies(fight_t *fight, entity_t *entity, my_vec_t *allies)
{
    int op = (*((spell_base_t **)entity->spells.data))->op;
    int max_dist = op + entity->stats->current_pm;
    sfVector2i counts = get_allies_counts(entity, max_dist);

    if (counts.x == 0)
        return 0;
    for (int i = 0; i < fight->nb_entities; i++) {
        if (fight->entities[i]->team == ENNEMIES
            || fight->entities[i]->alive != 1)
            continue;
        if (!counts.y
            || get_heuristic_cost(fight, entity->pos, fight->entities[i]->pos)
                <= max_dist)
            my_vec_push(allies, &fight->entities[i]);
    }
    return counts.y;
}
