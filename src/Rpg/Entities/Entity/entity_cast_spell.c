/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_cast_spell
*/

#include "Rpg/Entities/entity.h"
#include "Rpg/Fight/fight.h"

static void cast_effect(entity_t *from, entity_t *to, spell_effect_t *spell)
{
    effect_t effect;

    effect.lifetime = spell->lifetime;
    effect.spell = spell;
    effect.from = from;
    stats_add_effect(to->stats, &effect);
}

static void cast_debuff(entity_t *to, spell_debuff_t *spell)
{
    effect_t *effect;

    for (size_t i = 0; i < to->stats->effects.length; i++) {
        effect = ((effect_t *)to->stats->effects.data) + i;
        if ((effect->spell->type & spell->type) == 0)
            continue;
        if (spell->turns == 0)
            effect->lifetime = 0;
        else
            effect->lifetime -= spell->turns;
        if (effect->lifetime <= 0)
            my_vec_remove(&to->stats->effects, NULL, i--);
    }
}

void entity_cast_spell(entity_t *from, int to_cell)
{
    spell_base_t *spell = entity_get_select_spell(from);
    entity_t *to = from->fight->grid[to_cell].entity;

    if (!spell || from->stats->current_pa < spell->pa)
        return;
    from->stats->current_pa -= spell->pa;
    if (!to)
        return;
    if (spell->type == SPELL_ATTACK) {
        for (int i = 0; i < 4; i++)
            to->stats->life -= ((spell_attack_t *)spell)->damages[i]
                * (1 + from->stats->elements[i] / 30.f);
    }
    if (spell->type == SPELL_HEAL)
        to->stats->life += ((spell_heal_t *)spell)->heal
            * (1 + from->stats->elements[FIRE] / 50.f);
    if (spell->type == SPELL_EFFECT)
        cast_effect(from, to, (spell_effect_t *)spell);
    if (spell->type == SPELL_DEBUFF)
        cast_debuff(to, (spell_debuff_t *)spell);
}