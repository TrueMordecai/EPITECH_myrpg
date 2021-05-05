/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle_set_tactical
*/

#include "Rpg/rpg.h"

void battle_set_tactical(battle_t *battle)
{
    battle->tactical = !battle->tactical;
}
