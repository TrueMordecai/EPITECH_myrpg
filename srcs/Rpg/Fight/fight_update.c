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
    fight_reset_buff(fight);
    ally_draw_move_possibilities(fight);
    fight_place_rect(fight, fight_get_mouse_tile(fight), sfRed, WALKABLE);
}