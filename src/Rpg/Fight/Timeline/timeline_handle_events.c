/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline_handle_events
*/

#include <math.h>
#include <stdio.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/Fight/timeline.h"
#include "Rpg/rpg.h"

static void update_grabbed(
    timeline_t *timeline, sfEvent *event, sfRenderWindow *window)
{
    sfVector2i mouse_pos = {event->mouseButton.x, event->mouseButton.y};
    sfVector2f mouse_pos_view =
        sfRenderWindow_mapPixelToCoords(window, mouse_pos, timeline->view);
    sfVector2f bubble_pos = sfCircleShape_getPosition(timeline->bubble.circle);
    float dist;

    if (timeline->grabbed)
        return;
    dist = sqrtf(powf(mouse_pos_view.x - bubble_pos.x, 2)
        + powf(mouse_pos_view.y - bubble_pos.y, 2));
    if (dist < CIRCLE_RADIUS) {
        timeline->grabbed = 1;
        timeline->last_pos = mouse_pos;
    }
}

static void correct_pos(timeline_t *timeline, sfRenderWindow *window)
{
    sfVector2u win_size = sfRenderWindow_getSize(window);
    sfVector2i top_left = sfRenderWindow_mapCoordsToPixel(window,
        (sfVector2f){-CIRCLE_RADIUS * 1.6, -CIRCLE_RADIUS + 0.5 * FRAME_WIDTH},
        timeline->view);
    sfVector2i bottom_right = sfRenderWindow_mapCoordsToPixel(window,
        (sfVector2f){timeline->frames.length * (FRAME_WIDTH + FRAME_SPACING)
                - FRAME_SPACING,
            CIRCLE_RADIUS + 0.5 * FRAME_WIDTH},
        timeline->view);
    sfVector2f offset = {0, 0};

    if (top_left.x < 0)
        offset.x = top_left.x;
    if (top_left.y < 0)
        offset.y = top_left.y;
    if (offset.x == 0 && bottom_right.x > (int)win_size.x)
        offset.x = bottom_right.x - win_size.x;
    if (offset.y == 0 && bottom_right.y > (int)win_size.y)
        offset.y = bottom_right.y - win_size.y;
    sfView_move(timeline->view, offset);
}

static void update_pos(
    timeline_t *timeline, sfEvent *event, sfRenderWindow *window)
{
    sfVector2i mouse_pos = {event->mouseMove.x, event->mouseMove.y};

    sfView_move(timeline->view,
        (sfVector2f){timeline->last_pos.x - mouse_pos.x,
            timeline->last_pos.y - mouse_pos.y});
    timeline->last_pos = mouse_pos;
    correct_pos(timeline, window);
}

void timeline_handle_events(timeline_t *timeline, sfEvent *event)
{
    sfRenderWindow *window = timeline->fight->rpg->state->game_data->window;

    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft)
        update_grabbed(timeline, event, window);
    if (event->type == sfEvtMouseButtonReleased
        && event->mouseButton.button == sfMouseLeft && timeline->grabbed)
        timeline->grabbed = 0;
    if (event->type == sfEvtMouseMoved && timeline->grabbed)
        update_pos(timeline, event, window);
}