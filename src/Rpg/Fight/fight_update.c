/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_update
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

int fight_rm_dead_entity(fight_t *fight, int id)
{
    entity_t *entity;

    if (id < 0 || fight->nb_entities <= id)
        return 0;
    entity = fight->entities[id];
    if (!entity || entity->alive)
        return 0;
    fight->grid[entity->pos].entity = NULL;
    entity_update_spell_sight(fight->entities[fight->entity_turn]);
    if (id == fight->entity_turn && fight_new_entity(fight))
        return 1;
    return fight_end(fight);
}

void fight_rm_dead_entities(fight_t *fight)
{
    entity_t *entity;

    for (int i = 0; i < fight->nb_entities; i++) {
        entity = fight->entities[i];
        if (!entity->alive && fight->grid[entity->pos].entity == entity
            && fight_rm_dead_entity(fight, i))
            return;
    }
}

int fight_end(fight_t *fight)
{
    int ennemies = 0;
    int player = 0;

    for (int i = 0; i < fight->nb_entities; i++) {
        ennemies += (fight->entities[i]->alive
            && fight->entities[i]->team == ENNEMIES);
        player +=
            (fight->entities[i]->alive && fight->entities[i]->type == PLAYER);
    }
    if (!ennemies || !player) {
        battle_end(&fight->rpg->map->current_zone->battle);
        return 1;
    }
    return 0;
}

void fight_update(fight_t *fight, float dt)
{
    fight_reset_buff(fight);
    for (int i = 0; i < fight->nb_entities; i++)
        entity_update(fight->entities[i], dt, i == fight->entity_turn);
    fight_rm_dead_entities(fight);
}