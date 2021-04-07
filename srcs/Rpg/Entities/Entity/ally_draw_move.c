/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ally_draw_move
*/

#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

void ally_draw_move_possibilities(fight_t *fight)
{
    entity_t *entity = fight->entities[fight->entity_turn];
    int pm = entity->stats->current_pm;
    int *cells;

    if (entity->type == ENNEMY)
        return;
    cells = fight_get_range(fight, entity->pos, pm, WALKABLE);
    if (!cells)
        return;
    for (int i = 0; cells[i] != -2; i++)
        fight_place_rect(fight, cells[i], \
        sfColor_fromRGBA(0, 255, 0, 60), WALKABLE);
    free(cells);
}