/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline_destroy
*/

#include "Rpg/Fight/timeline.h"

void timeline_destroy(timeline_t *timeline)
{
    sfView_destroy(timeline->view);
    sfRectangleShape_destroy(timeline->time_rect);
    playing_bubble_destroy(&timeline->bubble);
    my_vec_free(&timeline->frames, &frame_destroy);
}