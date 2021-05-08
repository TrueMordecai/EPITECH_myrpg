/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** MyRPG draw
*/

#include "Rpg/rpg.h"

void rpg_draw(rpg_t *rpg)
{
    map_draw(rpg->map);
    if (!rpg->map->current_zone->is_battle)
        rpg_inventory_draw(rpg);
    if (rpg->quests.dialogue.is_talking == true)
        quests_draw(rpg);
}
