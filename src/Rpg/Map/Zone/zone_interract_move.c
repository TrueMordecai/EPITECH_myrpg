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
    int percentage = 0;

    if (special != AGGRO_10 && (special < AGGRO_100 || special > AGGRO_5))
        return;
    switch (special) {
        case AGGRO_5: percentage = 5; break;
        case AGGRO_10: percentage = 10; break;
        case AGGRO_20: percentage = 20; break;
        case AGGRO_30: percentage = 30; break;
        case AGGRO_50: percentage = 50; break;
        case AGGRO_75: percentage = 75; break;
        case AGGRO_100: percentage = 100; break;
        default: break;
    }
    if (get_randi(1, 100) > percentage)
        return;
    battle_start(&zone->battle);
}

int zone_interract_move(zone_t *zone)
{
    player_t *player = zone->map->rpg->player;
    sfVector2i pos = player->last_pos;
    int special;

    if (!zone->player_body || zone->is_battle)
        return 0;
    special = zone->special[pos.x + pos.y * zone->size.x];
    handle_aggro(zone, special);
    return 1;
}
