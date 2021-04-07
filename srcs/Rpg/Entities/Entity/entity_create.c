/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_create
*/

#include <stdlib.h>
#include "Rpg/Entities/entity.h"

entity_t *entity_create(void *datas, enum entity_type_e type, enum team_e team, int pos)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->datas = datas;
    entity->type = type;
    entity->team = team;
    entity->pos = pos;
    entity->stats = NULL;
    return entity;
}