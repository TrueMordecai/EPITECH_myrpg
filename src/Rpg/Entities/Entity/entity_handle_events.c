/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_handle_events
*/

#include "Rpg/Fight/fight.h"

void entity_handle_events(entity_t *entity, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (entity->spell_select == -1)
            entity_move(entity, 0);
        else
            entity_cast_spell(entity, entity->spell_cell);
    }
}