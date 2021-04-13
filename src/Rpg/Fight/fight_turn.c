/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_turn
*/

#include <libmy/printf.h>
#include "Rpg/Fight/fight.h"

void fight_new_turn(fight_t *fight)
{
    fight->turn++;
    fight->entity_turn = 0;
    entity_start_turn(fight->entities[fight->entity_turn]);
    my_printf("--- TURN %d ---\n", fight->turn);
    my_printf("    --- ENTITY %d ---\n", fight->entity_turn);
}

void fight_new_entity(fight_t *fight)
{
    entity_end_turn(fight->entities[fight->entity_turn++]);
    if (fight->entity_turn >= fight->nb_entities)
        fight_new_turn(fight);
    else {
        entity_start_turn(fight->entities[fight->entity_turn]);
        my_printf("    --- ENTITY %d ---\n", fight->entity_turn);
    }
}