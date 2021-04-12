/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player update.c
*/

#include "Rpg/rpg.h"

static void update_dir(player_t *player, sfVector2f offset)
{
    if (offset.x < 0)
        player->dir.x = -1;
    else if (offset.x > 0)
        player->dir.x = 1;
    if (offset.y < 0)
        player->dir.y = -1;
    else if (offset.y > 0)
        player->dir.y = 1;
    if ((offset.x == 0) ^ (offset.y == 0)) {
        player->dir.x -= player->dir.x * (offset.x == 0);
        player->dir.y -= player->dir.y * (offset.y == 0);
    }
}

void player_update(player_t *player, float dt)
{
    sfVector2f offset = {0, 0};
    float amplitude = 6;

    if (!player->body)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        offset.y = -amplitude;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        offset.y = amplitude;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        offset.x = -amplitude;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        offset.x = amplitude;
    update_dir(player, offset);
    if (offset.x != 0)
        player->body->velocity.x = offset.x;
    if (offset.y != 0)
        player->body->velocity.y = offset.y;
    player->pos = (sfVector2f){
        player->body->pos.x * M_TO_PX, (player->body->pos.y - 1) * M_TO_PX};
    sfRectangleShape_setPosition(player->rect, player->pos);
    (void)dt;
}
