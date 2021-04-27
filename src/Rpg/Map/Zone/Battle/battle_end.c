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
    battle->fight = NULL;
}