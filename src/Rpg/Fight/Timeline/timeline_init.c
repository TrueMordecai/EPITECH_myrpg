/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline_init
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/Fight/timeline.h"
#include "Rpg/rpg.h"
#include "GameEngine/game_head.h"

static void init_rects(timeline_t *timeline, int nb_entities)
{
    sfRectangleShape_setPosition(
        timeline->time_rect, (sfVector2f){0, FRAME_WIDTH - 5});
    sfRectangleShape_setSize(
        timeline->time_rect, (sfVector2f){FRAME_WIDTH, 0});
    sfRectangleShape_setFillColor(
        timeline->time_rect, sfColor_fromRGB(255, 154, 70));
}

static void init_frames(timeline_t *timeline, fight_t *fight)
{
    frame_t frame;

    for (int i = 0; i < fight->nb_entities; i++) {
        frame_init(&frame, fight->entities[i], i);
        my_vec_push(&timeline->frames, &frame);
    }
}

void timeline_init(timeline_t *timeline, fight_t *fight)
{
    timeline->view = sfView_create();
    timeline->time_past = 0;
    timeline->fight = fight;
    timeline->current = 0;
    timeline->grabbed = 0;
    timeline->time_rect = sfRectangleShape_create();
    init_rects(timeline, fight->nb_entities);
    playing_bubble_init(&timeline->bubble,
        get_font(&fight->rpg->state->game_data->assets, "roboto_font"));
    my_vec_init(&timeline->frames, sizeof(frame_t));
    init_frames(timeline, fight);
    sfView_setSize(timeline->view, (sfVector2f){1280, 720});
    sfView_setCenter(timeline->view, (sfVector2f){640, 360});
    sfView_move(timeline->view, (sfVector2f){-90, -30});
}