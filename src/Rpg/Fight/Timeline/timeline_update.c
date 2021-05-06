/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** timeline_update
*/

#include <stdio.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/Fight/timeline.h"
#include "Rpg/rpg.h"

void timeline_update_hovered(timeline_t *timeline, float dt)
{
    sfRenderWindow *window = timeline->fight->rpg->state->game_data->window;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_view =
        sfRenderWindow_mapPixelToCoords(window, mouse_pos, timeline->view);
    float hovered = mouse_pos_view.x / (FRAME_WIDTH + FRAME_SPACING);

    if (mouse_pos_view.x < 0 || mouse_pos_view.y < 0
        || mouse_pos_view.y > FRAME_WIDTH
        || (hovered - (int)hovered)
            >= FRAME_WIDTH / (FRAME_WIDTH + FRAME_SPACING)
        || (int)hovered >= timeline->frames.length) {
        timeline->hovered = -1;
        timeline->time_hovered = 0;
        return;
    }
    if (timeline->hovered != (int)hovered)
        timeline->time_hovered = 0;
    timeline->hovered = (int)hovered;
    timeline->time_hovered +=
        (timeline->time_hovered < INFO_WAIT * 2) ? dt : 0;
    return;
}

void timeline_update(timeline_t *timeline, float dt)
{
    timeline_update_hovered(timeline, dt);
    for (size_t i = 0; i < timeline->frames.length; i++)
        frame_update(((frame_t *)timeline->frames.data) + i);
}
