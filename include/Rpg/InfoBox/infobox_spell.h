/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_spell
*/

#ifndef INFOBOX_SPELL_H_
#define INFOBOX_SPELL_H_

#include "Rpg/InfoBox/infobox.h"
#include "Rpg/Fight/spell.h"

typedef struct infobox_spell_base {
    infobox_base_t base;
    spell_base_t *spell;
    enum spell_type_e type;
    sfText *name;
    /// PA, PO, TURN LIMIT, AREA, TYPE
    sfText *base_stats;
} infobox_spell_base_t;

typedef struct infobox_spell_attack {
    infobox_spell_base_t base;
    int nb_lines;
    sfText **damages;
} infobox_spell_attack_t;

typedef struct infobox_spell_heal {
    infobox_spell_base_t base;
    sfText *heal;
} infobox_spell_heal_t;

typedef struct infobox_spell_effect {
    infobox_spell_base_t base;
    sfText *type;
    my_vec_t boosts;
    my_vec_t damages;
} infobox_spell_effect_t;

typedef struct infobox_spell_debuff {
    infobox_spell_base_t base;
    sfText *type;
    my_vec_t boosts;
    my_vec_t damages;
} infobox_spell_debuff_t;

#endif /* !INFOBOX_SPELL_H_ */