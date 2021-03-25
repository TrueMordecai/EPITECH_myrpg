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
    sfVector2i player_pos = {battle->player->body->pos.x, battle->player->body->pos.y};
    sfVector2i size = {MIN(15, battle->size.x), MIN(15, battle->size.x)};
    sfVector2i pos = {player_pos.x - 7, player_pos.y - 7};

    //my_print("Player (%d, %d) -> Pos (%d, %d)\n", player_pos.x, player_pos.y, pos.x, pos.y);
    pos.x += MAX(0, 0 - pos.x);
    pos.y += MAX(0, 0 - pos.y);
    //my_print("Player (%d, %d) -> Pos (%d, %d)\n", player_pos.x, player_pos.y, pos.x, pos.y);
    //my_print("Min %d, %d\n", pos.x + size.x - battle->size.x, pos.y + size.y - battle->size.y);
    pos.x -= MAX(0, pos.x + size.x - battle->size.x);
    pos.y -= MAX(0, pos.y + size.y - battle->size.y);
    //my_print("Player (%d, %d) -> Pos (%d, %d)\n", player_pos.x, player_pos.y, pos.x, pos.y);
    battle->pos = pos;
    battle->zone->size = size;
    map_reset_zoom(battle->zone->map);
    //battle->zone->size = battle->size;
    pe_body_set_pos(battle->player->body, VEC2F(player_pos.x, player_pos.y));
    battle->player->body->velocity = VEC2F(0, 0);
    battle->zone->is_battle = 1;
}