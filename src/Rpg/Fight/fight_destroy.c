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
        if (fight->entities[i]->team == ENNEMIES)
            entity_destroy(fight->entities[i]);
        else
            fight->entities[i]->fight = NULL;
    }
    for (int i = 0; i < 10000; i++)
        sfRectangleShape_destroy(fight->rect_buffer[i]);
    timeline_destroy(&fight->timeline);
    free(fight->rect_buffer);
    free(fight->entities);
    free(fight->grid);
    free(fight);
}