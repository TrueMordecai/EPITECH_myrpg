/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_draw
*/

#include "Rpg/Fight/fight.h"

void fight_draw(fight_t *fight, sfRenderWindow *wind)
{
    sfUint32 transparent = sfColor_toInteger(sfTransparent);
    int i = 0;

    while (sfColor_toInteger(sfRectangleShape_getFillColor(\
    fight->rect_buffer[i])) != transparent) {
        sfRenderWindow_drawRectangleShape(wind, fight->rect_buffer[i], NULL);
        i++;
    }
    for (int x = 0; x < fight->size.x; x++) {
        for (int y = 0; y < fight->size.y; y++)
            entity_draw(fight->grid[x + y * fight->size.x].entity, wind);
    }
    for (int e = 0; e < fight->nb_entities; e++) {
        if (fight->entities[e]->alive > 0)
            continue;
        entity_draw(fight->entities[e], wind);
    }
    timeline_draw(&fight->timeline, wind);
    spells_bar_draw(&fight->spells_bar, wind);
    if (fight->timeline.time_hovered >= INFO_WAIT)
        infobox_draw(fight->infobox, wind);
}