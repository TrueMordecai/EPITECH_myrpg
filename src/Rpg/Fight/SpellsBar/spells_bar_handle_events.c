/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spells_bar_handle_events
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"
#include "Rpg/Fight/spells_bar.h"

void spells_bar_update_outlines(spells_bar_t *bar)
{
    for (int i = 0; i < bar->nb_frames; i++)
        sfRectangleShape_setOutlineColor(bar->frames[i],
            (i == bar->current_frame) ? sfColor_fromRGB(252, 120, 0)
                                      : sfBlack);
}

static int update_selected(
    spells_bar_t *bar, sfEvent *event, sfRenderWindow *window)
{
    sfVector2i mouse_pos = {event->mouseButton.x, event->mouseButton.y};
    sfVector2f view_pos =
        sfRenderWindow_mapPixelToCoords(window, mouse_pos, bar->view);
    sfVector2i spell_pos = {-1, -1};
    int id;

    spell_pos.x = view_pos.x / FRAME_WIDTH;
    spell_pos.y = view_pos.y / FRAME_WIDTH;
    if (view_pos.x < 0 || view_pos.y < 0 || spell_pos.x >= SPELLS_BAR_WIDTH
        || spell_pos.y >= SPELLS_BAR_HEIGHT)
        return 0;
    id = spell_pos.x + spell_pos.y * SPELLS_BAR_WIDTH;
    if (bar->current_frame == id)
        bar->current_frame = -1;
    else
        bar->current_frame = id;
    spells_bar_update_outlines(bar);
    spells_bar_update_entity_spell(bar);
    return 1;
}

int spells_bar_handle_events(spells_bar_t *bar, sfEvent *event)
{
    sfRenderWindow *window = bar->fight->rpg->state->game_data->window;

    if (spells_bar_handle_move(bar, event, window))
        return;
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft
        && update_selected(bar, event, window))
        return 1;
    return 0;
}