/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_handle_events
*/

#include "Rpg/Fight/fight.h"

void entity_handle_events(entity_t *entity, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        entity_move(entity);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyM) {
            entity->spell_select = (entity->spell_select) ? 0 : -1;
            entity_update_spell_sight(entity);
        }
        if (event.key.code == sfKeyI && entity->team == ENNEMIES)
            entity_compute_move(entity);
    }
}