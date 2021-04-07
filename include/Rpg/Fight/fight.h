/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight
*/

#ifndef RPG_FIGHT_H
#define RPG_FIGHT_H

#include <SFML/Graphics.h>
#include "Rpg/Entities/entity.h"
#include "Rpg/Map/physic.h"

enum cell_tests {WALKABLE = 1, OCCUPIED = 2, C_EMPTY = 4};
enum cell_flags {INEXISTING = -1, END_ARRAY = -2};

struct player_t;

typedef struct cell_t {
    entity_t *entity;
    int physic;
} cell_t;

typedef struct fight_t {
    entity_t **entities;
    int nb_entities;
    cell_t *grid;
    sfVector2i size;
    sfVector2i pos;
    int turn;
    int entity_turn;
    struct rpg_t *rpg;
    sfRectangleShape **rect_buffer;
} fight_t;

fight_t *fight_create(battle_t *battle, int nb_ennemies, \
struct player_t *player);
void fight_update(fight_t *fight, float dt);
void fight_draw(fight_t *fight, sfRenderWindow *wind);
void fight_destroy(fight_t *fight);

sfVector2i fight_pos_to_vec(fight_t *fight, int pos, int world);
sfVector2f fight_pos_to_world_vec(fight_t *fight, int pos);
int fight_vec_to_pos(fight_t *fight, sfVector2i vec);
int fight_xy_to_pos(fight_t *fight, int x, int y);
int fight_world_vec_to_pos(fight_t *fight, sfVector2f world_vec);
int fight_get_mouse_tile(fight_t *fight);
int *fight_get_range(fight_t *fight, int from, int range, int test);
int *fight_get_line(fight_t *fight, int from, int to);
void fight_draw_line(fight_t *fight, int from, int to);
void fight_show_sight(fight_t *fight, int from, int range, int need_free_cell);

void fight_reset_buff(fight_t *fight);
void fight_place_rect(fight_t *fight, int pos, sfColor color, int test);

int cell_is_walkable(cell_t *cell);
int cell_is_occupied(cell_t *cell);
int cell_is_empty(cell_t *cell);

#endif /* !FIGHT_H_ */