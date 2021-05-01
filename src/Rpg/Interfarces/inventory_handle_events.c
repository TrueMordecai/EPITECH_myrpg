/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** inventory_handle_input
*/

#include "Rpg/Interfarces/inventory.h"

void inventory_handle_events(inventory_t *inventory, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyA)
        inventory->is_open = !inventory->is_open;
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyI
        && event->key.control && event->key.shift)
        rpg_add_item_to_inventory(
            inventory->rpg, rpg_create_item(9, LEGENDARY));
}