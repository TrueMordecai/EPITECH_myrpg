/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** Rpg handle input
*/

#include "Rpg/rpg.h"
#include "My/my_display.h"

void rpg_handle_input(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        switch (event.key.code) {
        case sfKeyAdd:
            map_zoom_up_down(rpg->map, 1);
            break;
        case sfKeySubtract:
            map_zoom_up_down(rpg->map, 0);
            break;
        case sfKeyT:
            battle_set_tactical(&rpg->map->current_zone->battle);
            break;
        case sfKeyB:
            if (!rpg->map->current_zone->is_battle) {
                battle_start(&rpg->map->current_zone->battle);
            }
            else
                battle_end(&rpg->map->current_zone->battle);
            break;
        case sfKeyH:
            map_load_zone(rpg->map, "assets/Zones/house_test");
            break;
        case sfKeyV:
            map_load_zone(rpg->map, "assets/Zones/zone_test");
            break;
        default:
            break;
        }
    }
    player_handle_input(rpg->player, event);
}