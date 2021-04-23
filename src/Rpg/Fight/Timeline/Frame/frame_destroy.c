/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** frame_destroy
*/

#include "Rpg/Fight/timeline.h"

void frame_destroy(frame_t *frame)
{
    sfRectangleShape_destroy(frame->bg);
    sfRectangleShape_destroy(frame->life_bar);
    sfRectangleShape_destroy(frame->entity_rect);
}