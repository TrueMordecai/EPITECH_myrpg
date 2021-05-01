/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline
*/

#ifndef TIMELINE_H_
#define TIMELINE_H_

#include <libmy/collections/vec.h>
#include <sw/widget.h>
#include <sw/widgets/button.h>
#include <SFML/Graphics.h>

#include "Rpg/Entities/entity.h"

#define FRAME_WIDTH 64.0
#define FRAME_SPACING 5.0
#define CIRCLE_RADIUS 50

struct fight_t;

typedef struct frame {
    sfRectangleShape *entity_rect;
    sfRectangleShape *bg;
    sfRectangleShape *life_bar;
    entity_t *entity;
} frame_t;

typedef struct timeline {
    sw_button_t turn_btn;
    sfView *view;
    struct fight_t *fight;
    int current;
    int hovered;
    float time_hovered;
    sfVector2i last_pos;
    /// vector of frame_t
    my_vec_t frames;
    int grabbed;
} timeline_t;

void frame_init(frame_t *frame, entity_t *entity, int id);
void frame_update(frame_t *frame);
void frame_update_id(frame_t *frame, int new_id);
void frame_set_playing(frame_t *frame, int playing);
void frame_draw(frame_t *frame, sfRenderWindow *window);
void frame_destroy(void *frame_ptr);

void timeline_init(timeline_t *timeline, struct fight_t *fight);
void timeline_update_time(timeline_t *timeline, float dt);
void timeline_update(timeline_t *timeline, float dt);
int timeline_handle_events(timeline_t *timeline, sfEvent *event);
int timeline_get_entity_id(timeline_t *timeline, entity_t *entity);
void timeline_new_turn(timeline_t *timeline, entity_t *playing_entity);
void timeline_remove_entity(timeline_t *timeline, entity_t *entity);
void timeline_draw(timeline_t *timeline, sfRenderWindow *window);
void timeline_destroy(timeline_t *timeline);

#endif /* !TIMELINE_H_ */