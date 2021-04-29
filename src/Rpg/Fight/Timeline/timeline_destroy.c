/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline_destroy
*/

#include "Rpg/Fight/timeline.h"

void timeline_destroy(timeline_t *timeline)
{
    sw_button_drop(&timeline->turn_btn);
    sfView_destroy(timeline->view);
    my_vec_free(&timeline->frames, &frame_destroy);
}