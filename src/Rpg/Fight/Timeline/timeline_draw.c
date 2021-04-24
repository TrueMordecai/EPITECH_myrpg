/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline_draw
*/

#include "Rpg/Fight/timeline.h"

void timeline_draw(timeline_t *timeline, sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getView(window);

    sfRenderWindow_setView(window, timeline->view);
    sfRenderWindow_drawRectangleShape(window, timeline->time_rect, NULL);
    for (size_t i = 0; i < timeline->frames.length; i++)
        frame_draw(((frame_t *)timeline->frames.data) + i, window);
    sfRenderWindow_setView(window, view);
}