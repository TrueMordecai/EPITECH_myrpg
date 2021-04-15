/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** battle_stat
*/

#ifndef BATTLE_STAT_H_
#define BATTLE_STAT_H_

enum elements {EARTH, FIRE, WATER, WIND};

struct stats_t;

typedef struct effect_t {
    int lifetime;
    void (*effect)(struct stats_t *, int);
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
    effect_t *effects;
} stats_t;

stats_t *stats_create(void);
void stats_init(stats_t *stats, int *elements, int *resistances, int life);
void stats_init_pa_pm(stats_t *stats, int pa, int pm);
void stats_reset(stats_t *stats, int only_pa_pm);
void stats_destroy(stats_t *stats);

#endif /* !BATTLE_STAT_H_ */