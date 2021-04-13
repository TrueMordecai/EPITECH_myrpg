/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_destroy
*/

#include <stdlib.h>
#include "Rpg/Entities/entity.h"

void entity_destroy(entity_t *entity)
{
    free(entity->move_path);
    free(entity->move_possibilities);
    free(entity->spell_sight);
    free(entity->spell_range);
    if (entity->stats)
        stats_destroy(entity->stats);
    if (entity->rect)
        sfRectangleShape_destroy(entity->rect);
    free(entity);
}