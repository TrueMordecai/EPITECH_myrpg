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
#include "Rpg/Entities/animations.h"
#include "Rpg/Entities/stats.h"
#include "Rpg/Fight/spell.h"

struct fight_t;
struct rpg_t;

enum entity_state_e { IDLE, MOVING, CASTING_SPELL };
enum entity_type_e { PLAYER, ALLY, ENNEMY_CAC, ENNEMY_DIST };
enum team_e { ALLIES, ENNEMIES };
enum actions_e { MOVE, ATTACK };

struct move_action {
    my_vec_t path;
    int i;
    int len_path;
    float progress;
};

struct attack_action {
    float progress;
};

typedef struct action {
    int action_type;
    union {
        struct move_action move;
        struct attack_action attack;
    };
} action_t;

typedef struct entity_t {
    stats_t *stats;
    enum entity_type_e type;
    enum team_e team;
    enum entity_state_e state;
    int pos;
    int spell_select;
    int spell_cell;
    int alive;
    int *move_possibilities;
    my_vec_t *move_path;
    my_vec_t actions;
    my_vec_t spells;
    int *spell_sight;
    int *spell_range;
    void *datas;
    struct fight_t *fight;
    sfRectangleShape *rect;
    animations_t anim;
} entity_t;

entity_t *entity_create(
    void *datas, enum entity_type_e type, enum team_e team, int pos);
void entity_init(entity_t *entity);
void entity_init_rect(entity_t *entity, sfColor color);
void entity_move(entity_t *entity, int update_sprite);
void entity_update_sprite_pos(entity_t *entity, sfVector2f pos);
void entity_update(entity_t *entity, float dt, int playing);
void entity_update_alive(entity_t *entity);
void entity_handle_events(entity_t *entity, sfEvent event);
void entity_draw(entity_t *entity, sfRenderWindow *wind);
void entity_destroy(entity_t *entity);

void entity_start_turn(entity_t *entity);
void entity_end_turn(entity_t *entity);
void entity_compute_move(entity_t *entity);

void entity_attack(entity_t *entity);
void entity_init_spells(entity_t *entity, struct rpg_t *rpg);
void entity_add_spell(entity_t *entity, spell_base_t *spell);
spell_base_t *entity_get_select_spell(entity_t *entity);
void entity_cast_spell(entity_t *from, int to_cell);

void entity_add_action(entity_t *entity, enum actions_e action_type);
void entity_force_end_action(entity_t *entity, action_t *act);

void entity_update_move_possibilities(entity_t *entity);
void entity_draw_move_possibilities(entity_t *entity, int update);
void entity_update_move_path(entity_t *entity, my_vec_t *new_path);
void entity_draw_move_path(entity_t *entity, int update);
void entity_update_spell_sight(entity_t *entity);
void entity_draw_spell_sight(entity_t *entity, int update);
void entity_draw_spell_cell(entity_t *entity);

#endif /* !ENTITY_H_ */