/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** spells_bar_update
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/Fight/spells_bar.h"

void spells_bar_update_hovered(spells_bar_t *bar, float dt)
{
    int hovered = spells_bar_get_hovered(bar);

    bar->current_hovered = hovered;
    if (hovered == -1 || hovered != bar->current_hovered)
        bar->time_hovered = 0;
    if (hovered >= 0)
        bar->time_hovered += (bar->time_hovered < INFO_WAIT * 2) ? dt : 0;
}

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

    if (entity->team == ENNEMIES)
        return;
    spells_bar_set_selected(bar, entity->spell_select);
    spells_bar_update_spells(bar);
}

void spells_bar_update(spells_bar_t *bar, entity_t *entity, float dt)
{
    char buff[9];
    stats_t *stats;
    float life_ratio;
    entity_t *testing =
        ((entity->team == ENNEMIES) ? bar->last_entity : entity);

    if (!testing)
        return;
    spells_bar_update_hovered(bar, dt);
    stats = testing->stats;
    life_ratio = stats->current_life / (float)stats->life;
    bar->last_entity = testing;
    my_snprintf(
        buff, 9, "%d/%d PA", testing->stats->current_pa, testing->stats->pa);
    sfText_setString(bar->text_pa, buff);
    my_snprintf(
        buff, 9, "%d/%d PM", testing->stats->current_pm, testing->stats->pm);
    sfText_setString(bar->text_pm, buff);
    sfRectangleShape_setSize(bar->life,
        (sfVector2f){life_ratio * FRAME_WIDTH * SPELLS_BAR_WIDTH * 0.6, 15});
}
