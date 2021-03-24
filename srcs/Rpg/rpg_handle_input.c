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
        case sfKeyAdd:
            map_zoom(rpg->map, 1);
            break;
        case sfKeySubtract:
            map_zoom(rpg->map, 0);
            break;
        case sfKeyB:
            rpg->map->current_zone->is_battle = \
            !rpg->map->current_zone->is_battle;
            break;
        default:
            break;
        }
    }
    player_handle_input(rpg->player, event);
}