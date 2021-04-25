/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_cast_spell
*/

#include <libmy/printf.h>

#include "Rpg/Entities/entity.h"
#include "Rpg/Fight/fight.h"

static void cast_effect(entity_t *from, entity_t *to, spell_effect_t *spell)
{
    effect_t effect;
    int pm = to->stats->current_pm;

    effect.lifetime = spell->lifetime;
    effect.spell = spell;
    effect.from = from;
    stats_add_effect(to->stats, &effect);
    if (pm != to->stats->current_pm)
        entity_update_move_possibilities(to);
}

static void cast_debuff(entity_t *to, spell_debuff_t *spell)
{
    effect_t *effect;
    int pm = to->stats->current_pm;

    for (size_t i = 0; i < to->stats->effects.length; i++) {
        effect = ((effect_t *)to->stats->effects.data) + i;
        if ((effect->spell->type & spell->type) == 0)
            continue;
        if (spell->turns == 0)
            effect->lifetime = 0;
        else
            effect->lifetime -= spell->turns;
        if (effect->lifetime <= 0)
            stats_remove_effect(to->stats, i--, 1);
    }
    if (pm != to->stats->current_pm)
        entity_update_move_possibilities(to);
}

static void cast_spell(entity_t *from, entity_t *to, spell_base_t *spell)
{
    if (!to)
        return;
    if (spell->type == SPELL_ATTACK) {
        for (int i = 0; i < 4; i++)
            to->stats->current_life -= ((spell_attack_t *)spell)->damages[i]
                * (1 + from->stats->elements[i] / 30.f);
    }
    if (spell->type == SPELL_HEAL)
        to->stats->current_life += ((spell_heal_t *)spell)->heal
            * (1 + from->stats->elements[FIRE] / 50.f);
    if (spell->type == SPELL_EFFECT)
        cast_effect(from, to, (spell_effect_t *)spell);
    if (spell->type == SPELL_DEBUFF)
        cast_debuff(to, (spell_debuff_t *)spell);
    entity_update_alive(from);
    entity_update_alive(to);
}

void entity_cast_spell(entity_t *from, int to_cell)
{
    spell_base_t *spell = entity_get_select_spell(from);
    entity_t *to = from->fight->grid[to_cell].entity;
    int *area;

    if (!spell || from->spell_cell == -1 || from->stats->current_pa < spell->pa
        || spell->cast_left-- <= 0)
        return;
    from->stats->current_pa -= spell->pa;
    entity_add_action(from, ATTACK)->attack.cell = to_cell;
    if (spell->area > 1) {
        area = fight_get_range(from->fight, to_cell, spell->area, WALKABLE);
        if (!area)
            return;
        for (int i = 0; area[i] != END_ARRAY; i++) {
            to = from->fight->grid[area[i]].entity;
            cast_spell(from, to, spell);
        }
        free(area);
    } else
        cast_spell(from, from->fight->grid[to_cell].entity, spell);
}