/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** frame_draw
*/

#include "Rpg/Fight/timeline.h"

void frame_draw(frame_t *frame, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, frame->bg, NULL);
    sfRenderWindow_drawRectangleShape(window, frame->entity_rect, NULL);
    sfRenderWindow_drawRectangleShape(window, frame->life_bar, NULL);
}
