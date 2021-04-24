/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main loop of my hunter
*/

#include "Rpg/rpg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void rpg_inventory_mouse_input(rpg_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&      \
    (game->inventory.mouse_left == PRESS || game->inventory.mouse_left == HOLD)) {
        game->inventory.mouse_left = HOLD;
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        game->inventory.mouse_left = PRESS;
    else
        game->inventory.mouse_left = NOTHING;

}
