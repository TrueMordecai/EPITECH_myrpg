/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** allies_init
*/

#include "Rpg/Entities/allies.h"

void allies_init(allies_t *allies, struct rpg_t *rpg)
{
    allies->rpg = rpg;
    for (int i = 0; i < MAX_ALLIES_IN_FIGHT; i++)
        allies->selected_allies[i] = -1;
    my_vec_init(&allies->allies, sizeof(entity_t *));
    for (int i = 0; i < MAX_ALLIES_IN_FIGHT; i++)
        allies_add_random_ally(allies);
}
