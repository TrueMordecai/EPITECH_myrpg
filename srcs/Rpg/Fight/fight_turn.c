/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_turn
*/

#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

void fight_new_turn(fight_t *fight)
{
    fight->turn++;
    fight->entity_turn = 0;
    entity_start_turn(fight->entities[fight->entity_turn]);
    my_print("--- TURN %d ---\n", fight->turn);
    my_print("    --- ENTITY %d ---\n", fight->entity_turn);
}

void fight_new_entity(fight_t *fight)
{
    entity_end_turn(fight->entities[fight->entity_turn++]);
    if (fight->entity_turn >= fight->nb_entities)
        fight_new_turn(fight);
    else {
        entity_start_turn(fight->entities[fight->entity_turn]);
        my_print("    --- ENTITY %d ---\n", fight->entity_turn);
    }
}