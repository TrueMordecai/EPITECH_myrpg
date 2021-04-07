/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_handle_events
*/

#include "Rpg/Fight/fight.h"

void fight_handle_events(fight_t *fight, sfEvent event)
{
    if (event.type != sfEvtMouseButtonPressed)
        return;
    entity_move(fight->entities[0], fight_get_mouse_tile(fight));
}