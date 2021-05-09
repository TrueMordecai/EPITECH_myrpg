/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** timeline_init
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/Fight/timeline.h"
#include "Rpg/rpg.h"
#include "GameEngine/game_head.h"

static void init_frames(timeline_t *timeline, fight_t *fight)
{
    frame_t frame;

    for (int i = 0; i < fight->nb_entities; i++) {
        frame_init(&frame, fight->entities[i], i);
        my_vec_push(&timeline->frames, &frame);
    }
}

void on_button_click(sw_button_t *button, fight_t *fight)
{
    (void)button;
    fight_new_entity(fight);
}

static void init_button(timeline_t *timeline, fight_t *fight)
{
    sw_button_init(
        &timeline->turn_btn, NULL, (sw_button_on_click_t)&on_button_click);
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
    timeline->fight = fight;
    timeline->current = 0;
    timeline->grabbed = 0;
    my_vec_init(&timeline->frames, sizeof(frame_t));
    init_frames(timeline, fight);
    sfView_setSize(timeline->view, (sfVector2f){1280, 720});
    sfView_setCenter(timeline->view, (sfVector2f){640, 360});
    sfView_move(timeline->view, (sfVector2f){-(FRAME_WIDTH + 30), -30});
}
