/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ai_sight
*/

#include "Rpg/Fight/fight.h"

static void union_sights(int **sight, int *sight_tmp)
{
    if (!(*sight)) {
        *sight = sight_tmp;
        return;
    }
    for (int i = 0; (*sight)[i] != END_ARRAY; i++) {
        if ((*sight)[i] != 0 && sight_tmp[i] == 0)
            (*sight)[i] = 0;
    }
    free(sight_tmp);
}

static int get_ally_max_po(my_vec_t *allies, int ally_id)
{
    int max = 1;
    entity_t *ally = MY_VEC_GET_ELEM(entity_t *, allies, ally_id);
    spell_base_t *spell;

    for (size_t i = 0; i < ally->spells.length; i++) {
        spell = MY_VEC_GET_ELEM(spell_base_t *, &ally->spells, i);
        if (spell->po > max)
            max = spell->po;
    }
    return max;
}

int *init_sight(entity_t *entity, my_vec_t *allies, int ally_po)
{
    int po_entity = (*(spell_base_t **)entity->spells.data)->po;
    int po;
    fight_t *fight = entity->fight;
    int *sight = NULL;
    int *sight_tmp = NULL;

    if (ally_po)
        entity->fight->grid[entity->pos].entity = NULL;
    else
        entity_update_move_possibilities(entity);
    for (size_t i = 0; i < allies->length; i++) {
        po = (ally_po) ? get_ally_max_po(allies, i) : po_entity;
        sight_tmp = fight_get_sight(fight, (sfVector2i)\
        {MY_VEC_GET_ELEM(entity_t *, allies, i)->pos, \
            entity->stats->current_pm}, \
        (sfVector2i){po, 0}, &entity->move_possibilities);
        union_sights(&sight, sight_tmp);
    }
    return sight;
}