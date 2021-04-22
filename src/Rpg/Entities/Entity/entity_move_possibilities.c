/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ally_draw_move
*/

#include "Rpg/Fight/fight.h"

void free_tmp_path(my_vec_t *path);

static void verif_cells(fight_t *fight, int from, int *cells, size_t pm)
{
    my_vec_t *tmp;

    for (int i = 0; cells[i] != END_ARRAY; i++) {
        tmp = fight_get_path(fight, from, cells[i]);
        if (!tmp || tmp->length > pm + 1)
            cells[i] = -1;
        free_tmp_path(tmp);
    }
}

void entity_update_move_possibilities(entity_t *entity)
{
    fight_t *fight = entity->fight;
    size_t pm = entity->stats->current_pm;
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
    for (int i = 0; cells[i] != END_ARRAY; i++) {
        if (cells[i] == entity->pos)
            continue;
        fight_place_rect(fight, cells[i], \
        sfColor_fromRGBA(0, 255, 0, 60), WALKABLE);
    }
}

void entity_update_move_path(entity_t *entity, my_vec_t *new_path)
{
    fight_t *fight = entity->fight;

    free_tmp_path(entity->move_path);
    if (!new_path)
        new_path = fight_get_path(fight, entity->pos, \
        fight_get_mouse_tile(fight));
    entity->move_path = new_path;
    if (!entity->move_path)
        return;
    if (entity->move_path->length - 1 > (size_t)entity->stats->current_pm) {
        free_tmp_path(entity->move_path);
        entity->move_path = NULL;
    }
}

void entity_draw_move_path(entity_t *entity, int update)
{
    if (update)
        entity_update_move_path(entity, NULL);
    if (!entity->move_path)
        return;
    for (size_t i = 1; i < entity->move_path->length; i++)
        fight_place_rect(entity->fight, \
        MY_VEC_GET_ELEM(int, entity->move_path, i), \
        sfColor_fromRGBA(0, 255, 0, 120), WALKABLE);
}