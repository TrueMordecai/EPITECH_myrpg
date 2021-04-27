/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_turn
*/

#include <libmy/printf.h>
#include "Rpg/rpg.h"
#include "Rpg/Fight/fight.h"

static int get_next_entity(fight_t *fight, int from)
{
    while (from < fight->nb_entities && !fight->entities[from]->alive)
        from++;
    if (from >= fight->nb_entities)
        return -1;
    return from;
}

int fight_new_turn(fight_t *fight)
{
    fight->turn++;
    fight->entity_turn = get_next_entity(fight, 0);
    my_printf("Next entity from %d = %d\n", 0, fight->entity_turn);
    if (fight->entity_turn == -1)
        return fight_end(fight);
    entity_start_turn(fight->entities[fight->entity_turn]);
    my_printf("--- TURN %d ---\n", fight->turn);
    my_printf("    --- ENTITY %d ---\n", fight->entity_turn);
    return 0;
}

int fight_new_entity(fight_t *fight)
{
    int next_entity = get_next_entity(fight, fight->entity_turn + 1);

    entity_end_turn(fight->entities[fight->entity_turn++]);
    if (next_entity == -1)
        return fight_new_turn(fight);
    else {
        fight->entity_turn = next_entity;
        entity_start_turn(fight->entities[fight->entity_turn]);
        my_printf("    --- ENTITY %d ---\n", fight->entity_turn);
        return 0;
    }
}