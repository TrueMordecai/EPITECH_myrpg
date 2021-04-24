/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spells_bar_update
*/

#include "Rpg/Fight/spells_bar.h"
#include "Rpg/Fight/fight.h"

void spells_bar_update_entity_spell(spells_bar_t *bar)
{
    entity_t *entity = bar->fight->entities[bar->fight->entity_turn];

    entity->spell_select = bar->current_frame;
    entity_update_spell_sight(entity);
}

void spells_bar_set_selected(spells_bar_t *bar, int selected)
{
    bar->current_frame = selected;
    spells_bar_update_outlines(bar);
    spells_bar_update_entity_spell(bar);
}

void spells_bar_new_turn(spells_bar_t *bar)
{
    entity_t *entity = bar->fight->entities[bar->fight->entity_turn];

    spells_bar_set_selected(bar, entity->spell_select);
    spells_bar_update_spells(bar);
}