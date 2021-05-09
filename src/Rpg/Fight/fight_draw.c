/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** fight_draw
*/

#include "GameEngine/particle_manager.h"
#include "Rpg/rpg.h"
#include "Rpg/Fight/fight.h"

void fight_draw_line(fight_t *fight, int from, int to)
{
    int *line = fight_get_line(fight, from, to);
    int i = 0;

    if (!line)
        return;
    while (line[i] != END_ARRAY)
        fight_place_rect(
            fight, line[i++], sfColor_fromRGBA(0, 255, 255, 50), C_EMPTY);
    free(line);
}

static void draw_ui(fight_t *fight, sfRenderWindow *window)
{
    particle_manager_draw(
        fight->rpg->state->game_data->particles, window);
    timeline_draw(&fight->timeline, window);
    spells_bar_draw(&fight->spells_bar, window);
    if (fight->timeline.time_hovered >= INFO_WAIT
        || fight->spells_bar.time_hovered >= INFO_WAIT)
        infobox_draw(fight->infobox, window);
}

void fight_draw(fight_t *fight, sfRenderWindow *wind)
{
    sfUint32 transparent = sfColor_toInteger(sfTransparent);
    int i = 0;

    while (
        sfColor_toInteger(sfRectangleShape_getFillColor(fight->rect_buffer[i]))
        != transparent) {
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
    draw_ui(fight, wind);
}
