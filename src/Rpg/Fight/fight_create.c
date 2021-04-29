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

static int get_pos(fight_t *fight, int player_pos)
{
    my_vec_t *tmp = NULL;
    int i = 0;
    int pos;

    do {
        pos = get_randi(0, fight->size.x * fight->size.y - 1);
        if (!cell_is_empty(&fight->grid[pos]) || pos == player_pos)
            continue;
        tmp = fight_get_path(fight, pos, player_pos);
        i++;
    } while (!tmp && i < 100);
    if (tmp) {
        my_vec_free(tmp, NULL);
        free(tmp);
        return pos;
    }
    return -1;
}

static void init_ennemies(fight_t *fight, int nb_ennemies, int player_pos)
{
    for (int i = 0; i < nb_ennemies; i++) {
        int pos = get_pos(fight, player_pos);

        if (pos == -1) {
            nb_ennemies--;
            i--;
            fight->nb_entities--;
            continue;
        }
        fight->entities[i + 1] =
            entity_create(NULL, ENNEMY_CAC + i % 2, ENNEMIES, pos);
        entity_init_spells(fight->entities[i + 1], fight->rpg);
        fight->entities[i + 1]->stats = stats_create();
        fight->entities[i + 1]->fight = fight;
        entity_init_rect(fight->entities[i + 1], "Skeleton",
            sfColor_fromInteger((get_randi(0, 16777215) << 8) + 255));
        animations_update_rect(&fight->entities[i + 1]->anim);
    }
}

static void init_entities(fight_t *fight, int nb_ennemies, player_t *player)
{
    fight->entity_turn = 0;
    fight->nb_entities = MAX(0, nb_ennemies) + 1;
    fight->entities = malloc(sizeof(entity_t *) * fight->nb_entities);
    fight->entities[0] = player->entity;
    fight->entities[0]->pos = player->body->pos.x - fight->pos.x
        + (player->body->pos.y - fight->pos.y) * fight->size.x;
    init_ennemies(fight, nb_ennemies, fight->entities[0]->pos);
    for (int i = 0; i < fight->nb_entities; i++) {
        stats_reset(fight->entities[i]->stats, 0);
        animations_set_animation(&fight->entities[i]->anim, 0);
        animations_pause(&fight->entities[i]->anim);
        fight->entities[i]->fight = fight;
        fight->grid[fight->entities[i]->pos].entity = fight->entities[i];
        entity_init(fight->entities[i]);
        player->dir = (sfVector2i){0, 0};
        player->body->velocity = (pe_vec2f_t){0, 0};
        player->body->force = (pe_vec2f_t){0, 0};
    }
}

fight_t *fight_create(battle_t *battle, int nb_ennemies, player_t *player)
{
    fight_t *fight = malloc(sizeof(fight_t));

    fight->rpg = battle->zone->map->rpg;
    fight->size = battle->size;
    fight->pos = battle->pos;
    fight->turn = -1;
    fight->grid = malloc(sizeof(cell_t) * fight->size.x * fight->size.y);
    for (int x = 0; x < fight->size.x; x++) {
        for (int y = 0; y < fight->size.y; y++) {
            fight->grid[x + y * fight->size.x].entity = NULL;
            fight->grid[x + y * fight->size.x]
                .physic = battle->tiles[x + fight->pos.x
                + (y + fight->pos.y) * fight->rpg->map->current_zone->size.x];
        }
    }
    player->entity->alive = 1;
    init_entities(fight, nb_ennemies, player);
    init_rect_buff(fight, 10000);
    timeline_init(&fight->timeline, fight);
    spells_bar_init(&fight->spells_bar, fight);
    fight_new_turn(fight);
    fight->infobox =
        infobox_create(fight->rpg, INFOBOX_ENTITY, NULL, "roboto_font");
    return fight;
}