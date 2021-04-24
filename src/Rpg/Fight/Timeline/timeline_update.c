/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline_update
*/

#include <stdio.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/Fight/timeline.h"

void timeline_update_time(timeline_t *timeline, float dt)
{
    float new_height;

    timeline->time_past += dt;
    new_height = (timeline->time_past / TURN_TIME) * FRAME_WIDTH;
    sfRectangleShape_setPosition(timeline->time_rect,
        (sfVector2f){timeline->current * (FRAME_WIDTH + FRAME_SPACING),
            FRAME_WIDTH - new_height - 5});
    sfRectangleShape_setSize(
        timeline->time_rect, (sfVector2f){FRAME_WIDTH, new_height});
    if (timeline->time_past > TURN_TIME)
        fight_new_entity(timeline->fight);
}

void timeline_update(timeline_t *timeline, float dt)
{
    entity_t *current_entity;

    timeline_update_time(timeline, dt);
    for (size_t i = 0; i < timeline->frames.length; i++)
        frame_update(((frame_t *)timeline->frames.data) + i);
    current_entity = timeline->fight->entities[timeline->fight->entity_turn];
}