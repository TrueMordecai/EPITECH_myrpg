/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** battle_stat
*/

#ifndef BATTLE_STAT_H_
#define BATTLE_STAT_H_

#include <libmy/collections/vec.h>

enum elements {EARTH, FIRE, WATER, WIND};

struct stats_t;
struct spell_effect;
struct entity_t;

typedef struct effect_t {
    int lifetime;
    struct entity_t *from;
    struct spell_effect *spell;
} effect_t;

typedef struct stats_t {
    int current_life;
    int current_pm;
    int current_pa;
    int life;
    int pa;
    int pm;
    int elements[4];
    int resistances[4];
    my_vec_t effects;
} stats_t;

stats_t *stats_create(void);
void stats_init(stats_t *stats, int *elements, int *resistances, int life);
void stats_init_blank(stats_t *stats);
void stats_init_pa_pm(stats_t *stats, int pa, int pm);
void stats_reset(stats_t *stats, int only_pa_pm);
void stats_destroy(stats_t *stats);

void stats_add_effect(stats_t *stats, effect_t *effect);
void apply_effect_turn_start(stats_t *stats);
void apply_effect_turn_ends(stats_t *stats);
void update_effect_turn_ends(stats_t *stats);

#endif /* !BATTLE_STAT_H_ */