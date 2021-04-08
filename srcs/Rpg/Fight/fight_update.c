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
    int *pf = fight_get_path(fight, fight->entities[0]->pos, fight_get_mouse_tile(fight));

    fight_reset_buff(fight);
    ally_draw_move_possibilities(fight);
    //fight_show_sight(fight, fight->entities[0]->pos, 20, 0);
    fight_draw_line(fight, fight->entities[0]->pos, \
    fight_get_mouse_tile(fight));
    fight_place_rect(fight, fight_get_mouse_tile(fight), \
    sfColor_fromRGBA(255, 0, 0, 100), WALKABLE);
    for (int i = 0; pf && pf[i] != END_ARRAY; i++)
        fight_place_rect(fight, pf[i], sfGreen, EMPTY);
    free(pf);
}