/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_init
*/

#include "Rpg/Fight/fight.h"

void entity_init(entity_t *entity)
{
    entity->spell_select = -1;
    entity_start_turn(entity, 1);
}