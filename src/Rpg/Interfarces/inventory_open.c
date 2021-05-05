/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** inventory_open
*/

#include "Rpg/Interfarces/inventory.h"

void inventory_open(inventory_t *inv, sfBool open)
{
    inv->is_open = open;
}
