/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ally_draw_move
*/

#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

static void verif_cells(fight_t *fight, int from, int *cells, int pm)
{
    int *tmp;
    int size = 0;

    for (int i = 0; cells[i] != END_ARRAY; i++) {
        tmp = fight_get_path(fight, from, cells[i]);
        size = 0;
        for (int j = 0; tmp && tmp[j] != END_ARRAY; j++)
            size++;
        if (tmp && size <= pm + 1)
            free(tmp);
        else
            cells[i] = -1;
    }
}

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
    verif_cells(fight, entity->pos, cells, pm);
    for (int i = 0; cells[i] != -2; i++)
        fight_place_rect(fight, cells[i], \
        sfColor_fromRGBA(0, 255, 0, 60), WALKABLE);
    free(cells);
}