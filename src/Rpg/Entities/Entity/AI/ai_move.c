/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** ai_move
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"

void flee_away(entity_t *entity, my_vec_t *allies);
my_vec_t *get_nearest_side_path(
    fight_t *fight, int from, int to, size_t *min_len);
void free_tmp_path(my_vec_t *path);

void move_forward(entity_t *entity, my_vec_t *allies)
{
    my_vec_t *tmp;
    my_vec_t *path = NULL;
    size_t min_len = INT32_MAX;

    for (size_t i = 0; i < allies->length; i++) {
        tmp = get_nearest_side_path(entity->fight, entity->pos,
            MY_VEC_GET_ELEM(entity_t *, allies, i)->pos, &min_len);
        if (tmp) {
            path = tmp;
            break;
        }
    }
    free_tmp_path(entity->move_path);
    entity->move_path = path;
    entity_move(entity, 0);
}

void move_after_attack(entity_t *entity, my_vec_t *allies)
{
    if (entity->type == ENNEMY_DIST)
        flee_away(entity, allies);
    else
        move_forward(entity, allies);
}

static int get_ally(entity_t *entity, int *sight, int *range, my_vec_t *allies)
{
    size_t j;

    for (int i = 0; sight[i] != END_ARRAY; i++) {
        if (sight[i])
            continue;
        j = 0;
        while (j < allies->length
            && MY_VEC_GET_ELEM(entity_t *, allies, j)->pos != range[i])
            j++;
        if (j < allies->length)
            return j;
    }
    return -1;
}

static void attack(entity_t *entity, my_vec_t *allies)
{
    spell_attack_t *spell =
        MY_VEC_GET_ELEM(spell_attack_t *, &entity->spells, 0);
    int *range =
        fight_get_range(entity->fight, entity->pos, spell->base.po, WALKABLE);
    int *sight = fight_get_sight(entity->fight,
        (sfVector2i){entity->pos, spell->base.po}, (sfVector2i){-1, 0},
        &range);
    int ally = get_ally(entity, sight, range, allies);

    if (ally == -1)
        return;
    entity->spell_select = 0;
    while (
        spell->base.pa <= entity->stats->current_pa && spell->base.cast_left) {
        entity_cast_spell(
            entity, MY_VEC_GET_ELEM(entity_t *, allies, ally)->pos);
    }
    free(sight);
    free(range);
}

void move_to_reachable_sights(entity_t *entity, int *sight, my_vec_t *allies)
{
    my_vec_t *tmp;
    my_vec_t *path = NULL;
    size_t min_len = INT32_MAX;

    for (int i = 0; sight[i] != END_ARRAY; i++) {
        if (sight[i])
            continue;
        tmp = fight_get_path(
            entity->fight, entity->pos, entity->move_possibilities[i]);
        if (tmp && tmp->length < min_len) {
            min_len = tmp->length;
            free_tmp_path(path);
            path = tmp;
        } else
            free_tmp_path(tmp);
    }
    entity_update_move_path(entity, path);
    entity_move(entity, 0);
    attack(entity, allies);
    move_after_attack(entity, allies);
}
