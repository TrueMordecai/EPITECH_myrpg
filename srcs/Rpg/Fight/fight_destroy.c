/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_destroy
*/

#include "Rpg/Fight/fight.h"

void fight_destroy(fight_t *fight)
{
    for (int i = 0; i < fight->nb_entities; i++) {
        if (fight->entities[i]->type == ENNEMY)
            entity_destroy(fight->entities[i]);
    }
    free(fight->entities);
    free(fight->grid);
    free(fight);
}