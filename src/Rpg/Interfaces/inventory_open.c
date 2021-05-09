/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Opens the inventory
*/

#include "Rpg/Interfaces/inventory.h"

void inventory_open(inventory_t *inv, sfBool open)
{
    inv->is_open = open;
}
