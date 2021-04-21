/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_end_action
*/

#include "Rpg/rpg.h"

void entity_force_end_action(entity_t *entity, action_t *act)
{
    if (act->action_type == MOVE) {
        entity_update_sprite_pos(entity, (sfVector2f){-1, -1});
        my_vec_free(&act->move.path, NULL);
        animations_pause(&entity->anim);
    }
}