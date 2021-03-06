/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** timeline_new_turn
*/

#include "Rpg/Fight/timeline.h"

void timeline_new_turn(timeline_t *timeline, entity_t *playing_entity)
{
    timeline->current = timeline_get_entity_id(timeline, playing_entity);
    for (size_t i = 0; i < timeline->frames.length; i++)
        frame_set_playing((frame_t *)timeline->frames.data + i,
            i == (size_t)timeline->current);
}
