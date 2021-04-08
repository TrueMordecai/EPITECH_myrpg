/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_update
*/

#include "Rpg/Fight/fight.h"

void entity_update(entity_t *entity, float dt, int playing)
{
    if (!playing)
        return;
    if (entity->state == IDLE) {
        if (entity->spell_select < 0) {
            entity_draw_move_possibilities(entity, 0);
            entity_draw_move_path(entity, 1);
        } else
            entity_draw_spell_sight(entity, 0);
    }
}