/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** frame_update
*/

#include "Rpg/Fight/timeline.h"
#include "functions.h"

void frame_update(frame_t *frame)
{
    stats_t *stats = frame->entity->stats;
    float life_len = stats->current_life / (float)stats->life;

    life_len = MAX(1, life_len * FRAME_WIDTH);
    sfRectangleShape_setSize(frame->life_bar, (sfVector2f){life_len, 5});
}

void frame_update_id(frame_t *frame, int new_id)
{
    int y = sfRectangleShape_getPosition(frame->bg).y;

    sfRectangleShape_setPosition(frame->entity_rect,
        (sfVector2f){new_id * (FRAME_WIDTH + FRAME_SPACING), y});
    sfRectangleShape_setPosition(
        frame->bg, (sfVector2f){new_id * (FRAME_WIDTH + FRAME_SPACING), y});
    sfRectangleShape_setPosition(frame->life_bar,
        (sfVector2f){new_id * (FRAME_WIDTH + FRAME_SPACING), FRAME_WIDTH});
}

void frame_set_playing(frame_t *frame, int playing)
{
    int x = sfRectangleShape_getPosition(frame->bg).x;

    sfRectangleShape_setPosition(
        frame->entity_rect, (sfVector2f){x, -playing * 5});
    sfRectangleShape_setPosition(frame->bg, (sfVector2f){x, -playing * 5});
}