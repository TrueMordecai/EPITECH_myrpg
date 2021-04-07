/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity
*/

#ifndef ENTITY_H
#define ENTITY_H

#include "Rpg/Entities/stats.h"


struct fight_t;

enum entity_type_e {PLAYER, ALLY, ENNEMY};
enum team_e {ALLIES, ENNEMIES};

typedef struct entity_t {
    stats_t *stats;
    enum entity_type_e type;
    enum team_e team;
    int pos;
    void *datas;
    struct fight_t *fight;
} entity_t;

entity_t *entity_create(void *datas, enum entity_type_e type, \
enum team_e team, int pos);
void entity_move(entity_t *entity, int new_pos);
void entity_destroy(entity_t *entity);

void ally_draw_move_possibilities(struct fight_t *fight);

#endif /* !ENTITY_H_ */