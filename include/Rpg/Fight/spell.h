/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Spell data
*/

#ifndef SPELL_H_
#define SPELL_H_

#include "Rpg/Entities/stats.h"

typedef struct rpg rpg_t;

enum spell_type_e {
    SPELL_NONE,
    SPELL_ATTACK,
    SPELL_HEAL,
    SPELL_EFFECT,
    SPELL_DEBUFF
};
enum effect_type_e { EFFECT_NONE, EFFECT_DAMAGE, EFFECT_BOOST };

typedef struct spell_base {
    char *name;
    int texture_id;
    int po;
    int pa;
    int area;
    int cast_left;
    int turn_limit;
    enum spell_type_e type;
} spell_base_t;

typedef struct spell_attack {
    spell_base_t base;
    int damages[4];
} spell_attack_t;

typedef struct spell_heal {
    spell_base_t base;
    int heal;
} spell_heal_t;

typedef struct spell_effect {
    spell_base_t base;
    int lifetime;
    int max_cumul;
    enum effect_type_e type;
    int damages[4];
    stats_t buff;
} spell_effect_t;

typedef struct spell_debuff {
    spell_base_t base;
    enum effect_type_e type;
    int turns;
} spell_debuff_t;

void spells_init(rpg_t *rpg);
spell_base_t *get_spell(rpg_t *rpg, char const *name);

spell_base_t *spell_create_from_file(char *file);
void spell_destroy(spell_base_t *spell);

void spell_base_parse(spell_base_t *spell, char *file_content, size_t filesize);
void spell_attack_parse(
    spell_attack_t *spell, char *file_content, size_t filesize);
void spell_heal_parse(spell_heal_t *spell, char *file_content, size_t filesize);
void spell_debuff_parse(
    spell_debuff_t *spell, char *file_content, size_t filesize);
void spell_effect_parse(
    spell_effect_t *spell, char *file_content, size_t filesize);

enum effect_type_e parse_effect_type(char *line);

#endif /* !SPELL_H_ */
