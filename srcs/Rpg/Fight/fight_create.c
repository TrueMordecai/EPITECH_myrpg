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

static void init_rect_buff(fight_t *fight, int capacity)
{
    sfRectangleShape *rect;
    int tile_size = fight->rpg->map->tiles_size;

    fight->rect_buffer = malloc(sizeof(sfRectangleShape *) * capacity);
    for (int i = 0; i < capacity; i++) {
        rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(rect, sfTransparent);
        sfRectangleShape_setSize(rect, (sfVector2f){tile_size, tile_size});
        fight->rect_buffer[i] = rect;
    }
}

static void init_entities(fight_t *fight, int nb_ennemies, player_t *player)
{
    fight->entity_turn = 0;
    fight->nb_entities = MAX(0, nb_ennemies) + 1;
    fight->entities = malloc(sizeof(entity_t *) * fight->nb_entities);
    fight->entities[0] = player->entity;
    fight->entities[0]->pos = player->body->pos.x - fight->pos.x + \
    (player->body->pos.y - fight->pos.y) * fight->size.x;
    for (int i = 0; i < fight->nb_entities; i++)
        stats_reset(fight->entities[i]->stats, 0);
}

fight_t *fight_create(battle_t *battle, int nb_ennemies, player_t *player)
{
    fight_t *fight = malloc(sizeof(fight_t));

    fight->rpg = battle->zone->map->rpg;
    fight->size = battle->size;
    fight->pos = battle->pos;
    init_entities(fight, nb_ennemies, player);
    fight->turn = 0;
    fight->grid = malloc(sizeof(cell_t) * fight->size.x * fight->size.y);
    for (int x = 0; x < fight->size.x; x++) {
        for (int y = 0; y < fight->size.y; y++) {
            fight->grid[x + y * fight->size.x].entity = NULL;
            fight->grid[x + y * fight->size.x].physic = \
            battle->tiles[x + fight->pos.x + (y + fight->pos.y) * \
            fight->rpg->map->current_zone->size.x];
        }
    }
    init_rect_buff(fight, 100);
    return fight;
}