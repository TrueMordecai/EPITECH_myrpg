/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_handle_events
*/

#include "Rpg/Fight/fight.h"

void fight_handle_events(fight_t *fight, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyN)
        fight_new_entity(fight);
    entity_handle_events(fight->entities[fight->entity_turn], event);
}