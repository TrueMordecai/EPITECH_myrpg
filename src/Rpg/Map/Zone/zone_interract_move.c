/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone interract
*/

#include "Rpg/rpg.h"
#include "functions.h"

void handle_aggro(zone_t *zone, int special)
{
    if (special != AGGRO)
        return;
    if (get_randi(0, 100) >= 20)
        return;
    battle_start(&zone->battle);
}

int zone_interract_move(zone_t *zone)
{
    player_t *player = zone->map->rpg->player;
    sfVector2i pos = player->last_pos;
    int special;

    if (!zone->player_body)
        return 0;
    special = zone->special[pos.x + pos.y * zone->size.x];
    handle_aggro(zone, special);
    return 1;
}
