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
    if (entity->stats)
        stats_destroy(entity->stats);
    free(entity);
}