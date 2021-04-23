/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline_remove_frame
*/

#include "Rpg/Fight/timeline.h"

int timeline_get_entity_id(timeline_t *timeline, entity_t *entity)
{
    int id = -1;

    if (!entity)
        return id;
    for (size_t i = 0; i < timeline->frames.length; i++) {
        if ((((frame_t *)timeline->frames.data) + i)->entity == entity)
            return i;
    }
    return id;
}

void timeline_remove_entity(timeline_t *timeline, entity_t *entity)
{
    int id = timeline_get_entity_id(timeline, entity);
    frame_t *remove_frame;

    if (!entity || id == -1)
        return;
    remove_frame = ((frame_t *)timeline->frames.data) + id;
    frame_destroy(remove_frame);
    my_vec_remove(&timeline->frames, NULL, id);
    for (size_t i = id; i < timeline->frames.length; i++)
        frame_update_id(((frame_t *)timeline->frames.data) + i, i);
    if (timeline->bubble.last_entity == entity)
        timeline->bubble.last_entity = NULL;
    if (timeline->current <= id)
        return;
    timeline->current--;
    timeline_update_time(timeline, 0);
}