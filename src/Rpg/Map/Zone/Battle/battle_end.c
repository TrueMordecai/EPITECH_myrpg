/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle end
*/

#include "Rpg/rpg.h"
#include "Rpg/Fight/fight.h"

void battle_end(battle_t *battle)
{
    battle->pos = (sfVector2i){0, 0};
    battle->size = battle->zone->size;
    map_reset_zoom(battle->zone->map);
    battle->zone->is_battle = 0;
    fight_destroy(battle->fight);
    battle->player->body->velocity = (pe_vec2f_t){0, 0};
    battle->player->body->force = (pe_vec2f_t){0, 0};
    battle->player->dir = (sfVector2i){0, 0};
    battle->player->entity->anim.paused = 0;
    battle->fight = NULL;
}