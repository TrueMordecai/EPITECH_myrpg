/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity
*/

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.h>
#include <libmy/collections/vec.h>
#include "Rpg/Entities/stats.h"

struct fight_t;

enum entity_state_e {IDLE, MOVING, CASTING_SPELL};
enum entity_type_e {PLAYER, ALLY, ENNEMY_CAC, ENNEMY_DIST};
enum team_e {ALLIES, ENNEMIES};

typedef struct entity_t {
    stats_t *stats;
    enum entity_type_e type;
    enum team_e team;
    enum entity_state_e state;
    int pos;
    int spell_select;
    int *move_possibilities;
    my_vec_t *move_path;
    int *spell_sight;
    int *spell_range;
    void *datas;
    struct fight_t *fight;
    sfRectangleShape *rect;
} entity_t;

entity_t *entity_create(void *datas, enum entity_type_e type, \
enum team_e team, int pos);
void entity_init(entity_t *entity);
void entity_init_rect(entity_t *entity, sfColor color);
void entity_move(entity_t *entity);
void entity_update(entity_t *entity, float dt, int playing);
void entity_handle_events(entity_t *entity, sfEvent event);
void entity_draw(entity_t *entity, sfRenderWindow *wind);
void entity_destroy(entity_t *entity);

void entity_start_turn(entity_t *entity);
void entity_end_turn(entity_t *entity);
void entity_compute_move(entity_t *entity);

void entity_attack(entity_t *entity);

void entity_update_move_possibilities(entity_t *entity);
void entity_draw_move_possibilities(entity_t *entity, int update);
void entity_update_move_path(entity_t *entity, my_vec_t *new_path);
void entity_draw_move_path(entity_t *entity, int update);
void entity_update_spell_sight(entity_t *entity);
void entity_draw_spell_sight(entity_t *entity, int update);

#endif /* !ENTITY_H_ */