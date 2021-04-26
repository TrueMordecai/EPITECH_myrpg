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

static void init_rects(timeline_t *timeline)
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

void on_button_click(sw_button_t *button, void *fight_ptr)
{
    (void)button;
    fight_new_entity((fight_t *)fight_ptr);
}

static void init_button(timeline_t *timeline, fight_t *fight)
{
    sw_button_init(&timeline->turn_btn, NULL, &on_button_click);
    sw_button_set_texture(&timeline->turn_btn,
        get_texture(&fight->rpg->state->game_data->assets, "turn_pass"),
        SW_BUTTON_STATE_COUNT, 1);
    for (int i = 0; i < 4; i++)
        sw_button_set_texture_rect(
            &timeline->turn_btn, (sw_irect_t){i * 50, 0, 50, 25}, i);
    sw_set_size(&timeline->turn_btn, (sw_vec2f_t){50, 25});
    sw_set_position(&timeline->turn_btn, (sw_vec2f_t){-FRAME_WIDTH + 7, 30});
    sw_button_set_user_data(&timeline->turn_btn, fight);
}

void timeline_init(timeline_t *timeline, fight_t *fight)
{
    init_button(timeline, fight);
    timeline->view = sfView_create();
    timeline->time_hovered = 0;
    timeline->hovered = -1;
    timeline->time_past = 0;
    timeline->fight = fight;
    timeline->current = 0;
    timeline->grabbed = 0;
    timeline->time_rect = sfRectangleShape_create();
    init_rects(timeline);
    my_vec_init(&timeline->frames, sizeof(frame_t));
    init_frames(timeline, fight);
    sfView_setSize(timeline->view, (sfVector2f){1280, 720});
    sfView_setCenter(timeline->view, (sfVector2f){640, 360});
    sfView_move(timeline->view, (sfVector2f){-(FRAME_WIDTH + 30), -30});
}