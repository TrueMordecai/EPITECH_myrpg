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
    if (sfKeyboard_isKeyPressed(sfKeyA))
        rpg_add_item_to_inventory(rpg, rpg_create_item(2, 4));
    rpg_inventory_draw(rpg);
}
