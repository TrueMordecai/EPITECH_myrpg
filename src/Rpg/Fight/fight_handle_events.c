/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_handle_events
*/

#include "Rpg/Fight/fight.h"

void fight_handle_events(fight_t *fight, sfEvent event)
{
    if (spells_bar_handle_events(&fight->spells_bar, &event))
        return;
    timeline_handle_events(&fight->timeline, &event);
    entity_handle_events(fight->entities[fight->entity_turn], event);
}