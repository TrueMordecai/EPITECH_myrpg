/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** Rpg handle input
*/

#include "Rpg/rpg.h"

void rpg_handle_input(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        switch (event.key.code) {
        case sfKeyUp:
            map_move(rpg->map, (sfVector2f){0, 10});
            break;
        case sfKeyRight:
            map_move(rpg->map, (sfVector2f){-10, 0});
            break;
        case sfKeyDown:
            map_move(rpg->map, (sfVector2f){0, -10});
            break;
        case sfKeyLeft:
            map_move(rpg->map, (sfVector2f){10, 0});
            break;
        case sfKeyAdd:
            map_zoom(rpg->map, 1);
            break;
        case sfKeySubtract:
            map_zoom(rpg->map, 0);
            break;
        default:
            break;
        }
    }
    player_handle_input(rpg->player, event);
}