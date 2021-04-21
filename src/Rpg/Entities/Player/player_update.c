/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player update.c
*/

#include <libmy/printf.h>

#include "Rpg/rpg.h"

void player_update_anim_dir(
    player_t *player, sfVector2f offset, sfVector2i start_dir)
{
    if (offset.x == 0 && offset.y == 0) {
        animations_reset(&player->entity->anim);
        player->entity->anim.paused = 1;
    } else
        player->entity->anim.paused = 0;
    if (start_dir.x != player->dir.x || player->dir.y != start_dir.y) {
        if (player->dir.y)
            animations_set_animation(
                &player->entity->anim, (player->dir.y == -1));
        if (player->dir.x)
            animations_set_animation(
                &player->entity->anim, 2 + (player->dir.x == 1));
    }
}

static void update_dir(player_t *player, sfVector2f offset)
{
    sfVector2i dir = player->dir;

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
    if (player->entity->fight == NULL)
        player_update_anim_dir(player, offset, dir);
}

void player_update(player_t *player, float dt)
{
    sfVector2f offset = {0, 0};
    float amplitude = 6;

    animations_update(&player->entity->anim, dt);
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
        player->body->pos.x * M_TO_PX, (player->body->pos.y) * M_TO_PX};
    sfRectangleShape_setPosition(player->entity->rect, player->pos);
}
