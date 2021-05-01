/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** rpg update
*/

#include "Rpg/rpg.h"
void rpg_update(rpg_t *rpg, float dt)
{
    player_update(rpg->player, dt);
    map_update(rpg->map, dt);
}