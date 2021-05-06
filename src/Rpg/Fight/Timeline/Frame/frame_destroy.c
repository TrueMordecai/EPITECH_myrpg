/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** frame_destroy
*/

#include "Rpg/Fight/timeline.h"

void frame_destroy(void *frame_ptr)
{
    frame_t *frame = (frame_t *)frame_ptr;

    sfRectangleShape_destroy(frame->bg);
    sfRectangleShape_destroy(frame->life_bar);
    sfRectangleShape_destroy(frame->entity_rect);
}
