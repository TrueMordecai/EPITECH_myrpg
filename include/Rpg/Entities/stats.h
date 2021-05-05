/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** battle_stat
*/

#ifndef BATTLE_STAT_H_
#define BATTLE_STAT_H_

#include <libmy/collections/vec.h>

#define XP_TO_LEVEL_UP 100
enum elements { EARTH, FIRE, WATER, WIND };

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
    int level;
    int xp;
    int elements[4];
    int resistances[4];
    my_vec_t effects;
} stats_t;

stats_t *stats_create(void);
void stats_init(stats_t *stats, int *elements, int *resistances, int life);
void stats_init_blank(stats_t *stats);
void stats_init_pa_pm(stats_t *stats, int pa, int pm);
void stats_init_from_level(stats_t *stats, int level);
void stats_reset(stats_t *stats, int only_pa_pm);
void stats_destroy(stats_t *stats);

void stats_level_up(stats_t *stats);
void stats_gain_xp(stats_t *stats, int xp);

int stats_compute_damages(stats_t *from, stats_t *to, int element, int value);

void stats_add_effect(stats_t *stats, effect_t *effect);
void stats_remove_effect(stats_t *stats, int effect_id, int debuff);
void stats_clear_effects(stats_t *stats);
void apply_effect_turn_start(stats_t *stats);
void apply_effect_turn_ends(stats_t *stats);
void update_effect_turn_ends(stats_t *stats);

int stats_update(stats_t *stats);
void stats_display(stats_t *stats);

#endif /* !BATTLE_STAT_H_ */
