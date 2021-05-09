/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** player_update_equipement
*/

#include "Rpg/Entities/player.h"
#include "Rpg/Fight/fight.h"
#include "Rpg/Interfaces/inventory.h"
#include "Rpg/rpg.h"

void player_remove_equipment_stats(player_t *player)
{
    item_t *item;
    entity_t *entity = player->entity;

    for (int i = 0; i < 4; i++) {
        item = entity->fight->rpg->inventory.equipement + i;
        if (item->name == NULL)
            continue;
        entity->stats->life -= item->life;
        entity->stats->elements[EARTH] -= item->earth;
        entity->stats->elements[FIRE] -= item->fire;
        entity->stats->elements[WATER] -= item->water;
        entity->stats->elements[WIND] -= item->wind;
        entity->stats->resistances[EARTH] -= item->res_earth;
        entity->stats->resistances[FIRE] -= item->res_fire;
        entity->stats->resistances[WATER] -= item->res_water;
        entity->stats->resistances[WIND] -= item->res_wind;
    }
}

void player_set_equipment_stats(player_t *player)
{
    item_t *item;
    entity_t *entity = player->entity;

    for (int i = 0; i < 4; i++) {
        item = entity->fight->rpg->inventory.equipement + i;
        if (item->name == NULL)
            continue;
        entity->stats->life += item->life;
        entity->stats->elements[EARTH] += item->earth;
        entity->stats->elements[FIRE] += item->fire;
        entity->stats->elements[WATER] += item->water;
        entity->stats->elements[WIND] += item->wind;
        entity->stats->resistances[EARTH] += item->res_earth;
        entity->stats->resistances[FIRE] += item->res_fire;
        entity->stats->resistances[WATER] += item->res_water;
        entity->stats->resistances[WIND] += item->res_wind;
    }
}
