/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spells_bar_update_spells
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"
#include "Rpg/Fight/spells_bar.h"

static void update_frame(spells_bar_t *bar, int i, spell_base_t *spell)
{
    sfIntRect rect;
    
    if (spell) {
        rect = (sfIntRect){(spell->type - 1) * 64, 0, 64, 64};
        sfRectangleShape_setTextureRect(bar->frames[i], rect);
        sfRectangleShape_setFillColor(bar->frames[i], sfWhite);
    } else
        sfRectangleShape_setFillColor(bar->frames[i], sfTransparent);
}

void spells_bar_update_spells(spells_bar_t *bar)
{
    entity_t *entity = bar->fight->entities[bar->fight->entity_turn];

    for (int i = 0; i < bar->nb_frames; i++) {
        if ((size_t)i < entity->spells.length)
            update_frame(
            bar, i, MY_VEC_GET_ELEM(spell_base_t *, &entity->spells, i));
        else
            update_frame(bar, i, NULL);
    }
}