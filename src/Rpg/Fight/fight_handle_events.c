/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_handle_events
*/

#include "Rpg/Fight/fight.h"

void fight_handle_events(fight_t *fight, sfEvent event)
{
    timeline_handle_events(&fight->timeline, &event);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyN)
        if (fight_new_entity(fight))
            return;
    entity_handle_events(fight->entities[fight->entity_turn], event);
}