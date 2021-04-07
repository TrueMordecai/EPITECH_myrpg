/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity
*/

#ifndef ENTITY_H
#define ENTITY_H

#include "Rpg/Entities/stats.h"

enum entity_type_e {PLAYER, ALLY, ENNEMY};
enum team_e {ALLIES, ENNEMIES};

typedef struct entity_t {
    stats_t *stats;
    enum entity_type_e type;
    enum team_e team;
    int pos;
    void *datas;
} entity_t;

entity_t *entity_create(void *datas, enum entity_type_e type, enum team_e team, int pos);
void entity_destroy(entity_t *entity);

#endif /* !ENTITY_H_ */