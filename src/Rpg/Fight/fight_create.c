/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_create
*/

#include <libmy/printf.h>
#include <stdlib.h>
#include <stdio.h>

#include "Rpg/Entities/player.h"
#include "Rpg/Fight/fight.h"
#include "Rpg/Map/battle.h"
#include "Rpg/rpg.h"
#include "functions.h"

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

static void init_grid(fight_t *fight, battle_t *battle)
{
    fight->grid = malloc(sizeof(cell_t) * fight->size.x * fight->size.y);
    for (int x = 0; x < fight->size.x; x++) {
        for (int y = 0; y < fight->size.y; y++) {
            fight->grid[x + y * fight->size.x].entity = NULL;
            fight->grid[x + y * fight->size.x]
                .physic = battle->tiles[x + fight->pos.x
                + (y + fight->pos.y) * fight->rpg->map->current_zone->size.x];
        }
    }
}

static void init_ui(fight_t *fight)
{
    timeline_init(&fight->timeline, fight);
    spells_bar_init(&fight->spells_bar, fight);
    fight->infobox =
        infobox_create(fight->rpg, INFOBOX_ENTITY, NULL, "roboto_font");
}

fight_t *fight_create(battle_t *battle, int nb_ennemies, player_t *player)
{
    fight_t *fight = malloc(sizeof(fight_t));

    fight->rpg = battle->zone->map->rpg;
    fight->size = battle->size;
    fight->pos = battle->pos;
    fight->turn = -1;
    init_grid(fight, battle);
    fight_init_entities(fight, nb_ennemies, player);
    init_rect_buff(fight, 10000);
    init_ui(fight);
    fight_new_turn(fight);
    player->dir = (sfVector2i){0, 0};
    return fight;
}