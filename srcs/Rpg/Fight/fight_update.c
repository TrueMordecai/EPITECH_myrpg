/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_update
*/

#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

void fight_update(fight_t *fight, float dt)
{
    int mouse_tile = fight_get_mouse_tile(fight);
    fight_reset_buff(fight);
    if (mouse_tile >= 0)
        fight_place_rect(fight, mouse_tile, sfGreen, WALKABLE);
}