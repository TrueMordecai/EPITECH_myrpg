/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle init
*/

#include "Rpg/rpg.h"
#include "My/my_memory.h"

void battle_init(battle_t *battle, zone_t *zone)
{
    battle->tactical = 1;
    battle->zone = zone;
    battle->size = zone->size;
    battle->pos = (sfVector2i){0, 0};
    battle->tiles = my_calloc(sizeof(int) * battle->size.x * battle->size.y, EMPTY);
    battle->layer = layer_create(NULL, battle->zone->tiles_size);
    battle->player = zone->map->rpg->player;
}