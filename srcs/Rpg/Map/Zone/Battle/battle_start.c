/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle start
*/

#include "Rpg/rpg.h"
#include "My/my_display.h"

void battle_start(battle_t *battle)
{
    sfVector2i player_pos = {battle->player->body->pos.x, \
        battle->player->body->pos.y};
    sfVector2i size = {MIN(15, battle->size.x), MIN(15, battle->size.x)};
    sfVector2i pos = {player_pos.x - 7, player_pos.y - 7};

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
}