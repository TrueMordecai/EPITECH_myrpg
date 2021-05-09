/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** An infobox that describes a spell
*/

#ifndef INFOBOX_SPELL_H_
#define INFOBOX_SPELL_H_

#include "Rpg/Fight/spell.h"
#include "Rpg/InfoBox/infobox.h"

typedef struct infobox_spell_base {
    infobox_base_t base;
    spell_base_t *spell;
    sfText *name;
    sfText *ap;
    sfText *op;
    sfText *turn_limit;
    sfText *area;
    sfText *type;
} infobox_spell_base_t;

typedef struct infobox_spell_attack {
    infobox_spell_base_t base;
    int nb_lines;
    sfText *damages;
    sfText **elements[2];
} infobox_spell_attack_t;

typedef struct infobox_spell_heal {
    infobox_spell_base_t base;
    sfText *heal;
} infobox_spell_heal_t;

typedef struct infobox_spell_effect {
    infobox_spell_base_t base;
    sfText *max_cumul;
    sfText *lifetime;
    sfText *boost;
    sfText *damage;
    my_vec_t boosts;
    my_vec_t damages;
} infobox_spell_effect_t;

typedef struct infobox_spell_debuff {
    infobox_spell_base_t base;
    sfText *type;
    sfText *turn_removed;
} infobox_spell_debuff_t;

void infobox_spell_init(infobox_spell_base_t *info, spell_base_t *spell);
void infobox_spell_set_spell(
    infobox_spell_base_t **info_ptr, spell_base_t *spell);
void infobox_spell_draw(infobox_spell_base_t *info, sfRenderWindow *window);
void infobox_spell_destroy(infobox_spell_base_t *info);

void infobox_spell_attack_init(
    infobox_spell_attack_t *info, spell_attack_t *spell);
void infobox_spell_attack_set_spell(
    infobox_spell_attack_t *info, spell_attack_t *spell);
void infobox_spell_attack_draw(
    infobox_spell_attack_t *info, sfRenderWindow *window);
void infobox_spell_attack_destroy_lines(infobox_spell_attack_t *info);
void infobox_spell_attack_destroy(infobox_spell_attack_t *info);

void infobox_spell_heal_init(infobox_spell_heal_t *info, spell_heal_t *spell);
void infobox_spell_heal_set_spell(
    infobox_spell_heal_t *info, spell_heal_t *spell);
void infobox_spell_heal_draw(
    infobox_spell_heal_t *info, sfRenderWindow *window);
void infobox_spell_heal_destroy(infobox_spell_heal_t *info);

void infobox_spell_debuff_init(
    infobox_spell_debuff_t *info, spell_debuff_t *spell);
void infobox_spell_debuff_set_spell(
    infobox_spell_debuff_t *info, spell_debuff_t *spell);
void infobox_spell_debuff_draw(
    infobox_spell_debuff_t *info, sfRenderWindow *window);
void infobox_spell_debuff_destroy(infobox_spell_debuff_t *info);

void infobox_spell_effect_init(
    infobox_spell_effect_t *info, spell_effect_t *spell);
void infobox_spell_effect_set_spell(
    infobox_spell_effect_t *info, spell_effect_t *spell);
void infobox_spell_effect_draw(
    infobox_spell_effect_t *info, sfRenderWindow *window);
void infobox_spell_effect_clear_vecs(infobox_spell_effect_t *info);
void infobox_spell_effect_destroy(infobox_spell_effect_t *info);

#endif /* !INFOBOX_SPELL_H_ */
