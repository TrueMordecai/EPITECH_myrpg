/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_create
*/

#include <stdlib.h>
#include "Rpg/Entities/player.h"
#include "Rpg/Map/battle.h"
#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

fight_t *fight_create(battle_t *battle, int nb_ennemies, player_t *player)
{
    fight_t *fight = malloc(sizeof(fight_t));

    fight->rpg = battle->zone->map->rpg;
    fight->size = battle->size;
    fight->nb_entities = MAX(0, nb_ennemies) + 1;
    fight->entities = malloc(sizeof(entity_t *) * fight->nb_entities);
    fight->entities[0] = player->entity;
    fight->entities[0]->pos = player->body->pos.x - battle->pos.x + (player->body->pos.y - battle->pos.y) * fight->size.x;
    fight->turn = 0;
    fight->grid = malloc(sizeof(cell_t) * fight->size.x * fight->size.y);
    for (int x = 0; x < fight->size.x; x++) {
        for (int y = 0; y < fight->size.y; y++) {
            fight->grid[x + y * fight->size.x].entity = NULL;
            fight->grid[x + y * fight->size.x].physic = battle->tiles[x + y * fight->size.x];
        }
    }
    return fight;
}