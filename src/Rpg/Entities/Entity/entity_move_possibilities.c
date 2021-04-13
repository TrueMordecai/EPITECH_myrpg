/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ally_draw_move
*/

#include "Rpg/Fight/fight.h"

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

void entity_update_move_possibilities(entity_t *entity)
{
    fight_t *fight = entity->fight;
    int pm = entity->stats->current_pm;
    int *cells;

    free(entity->move_possibilities);
    cells = fight_get_range(fight, entity->pos, pm, WALKABLE);
    if (!cells)
        return;
    verif_cells(fight, entity->pos, cells, pm);
    entity->move_possibilities = cells;
}

void entity_draw_move_possibilities(entity_t *entity, int update)
{
    fight_t *fight = entity->fight;
    int *cells;

    if (update)
        entity_update_move_possibilities(entity);
    cells = entity->move_possibilities;
    if (!cells)
        return;
    for (int i = 0; cells[i] != END_ARRAY; i++)
        fight_place_rect(fight, cells[i], \
        sfColor_fromRGBA(0, 255, 0, 60), WALKABLE);
}

void entity_update_move_path(entity_t *entity)
{
    fight_t *fight = entity->fight;
    int size = 0;

    free(entity->move_path);
    entity->move_path = fight_get_path(fight, entity->pos, \
    fight_get_mouse_tile(fight));
    if (!entity->move_path)
        return;
    for (int i = 0; entity->move_path[i] != END_ARRAY; i++)
        size++;
    if (size - 1 > entity->stats->current_pm) {
        free(entity->move_path);
        entity->move_path = NULL;
    }
}

void entity_draw_move_path(entity_t *entity, int update)
{
    if (update)
        entity_update_move_path(entity);
    if (!entity->move_path)
        return;
    for (int i = 0; entity->move_path[i] != END_ARRAY; i++)
        fight_place_rect(entity->fight, entity->move_path[i], \
        sfColor_fromRGBA(0, 255, 0, 120), WALKABLE);
}