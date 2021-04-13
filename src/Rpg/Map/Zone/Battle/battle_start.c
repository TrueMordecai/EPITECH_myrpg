/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle start
*/

#include <libmy/memory/alloc.h>

#include "Rpg/rpg.h"
#include "functions.h"
#include "Rpg/Fight/fight.h"

static sfVector2i get_size(battle_t *battle)
{
    int width = get_rand(10, MIN(31, battle->size.x + 1));
    sfVector2i size = {width,
        width * battle->zone->map->view_size.y / battle->zone->map->view_size.x
            + 0.5f};

    return size;
}

void battle_start(battle_t *battle)
{
    sfVector2i player_pos = {
        battle->player->body->pos.x, battle->player->body->pos.y};
    sfVector2i size = get_size(battle);
    sfVector2i pos = {player_pos.x - size.x / 2, player_pos.y - size.y / 2};

    get_size(battle);
    pos.x += MAX(0, 0 - pos.x);
    pos.y += MAX(0, 0 - pos.y);
    pos.x -= MAX(0, pos.x + size.x - battle->size.x);
    pos.y -= MAX(0, pos.y + size.y - battle->size.y);
    battle->pos = pos;
    battle->size = size;
    map_reset_zoom(battle->zone->map);
    pe_body_set_pos(battle->player->body, VEC2F(player_pos.x, player_pos.y));
    battle->player->body->velocity = VEC2F(0, 0);
    battle->zone->is_battle = 1;
    battle->fight = fight_create(battle, 1, battle->player);
}
