/*
** EPITECH PROJECT, 2021
** rpg
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
    entity_add_action(entity, ATTACK)->attack.cell =
        MY_VEC_GET_ELEM(entity_t *, allies, 0)->pos;
    move_after_attack(entity, allies);
}