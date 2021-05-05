/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** rpg draw
*/

#include "Rpg/rpg.h"

void rpg_draw(rpg_t *rpg)
{
    map_draw(rpg->map);
    if (!rpg->map->current_zone->is_battle)
        rpg_inventory_draw(rpg);
    if (rpg->battle_end.is_on)
        battle_end_draw(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyA))
        rpg_add_item_to_inventory(rpg, rpg_create_item(9, LEGENDARY));
    rpg_inventory_draw(rpg);
}
