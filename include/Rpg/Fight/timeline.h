/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** timeline
*/

#ifndef TIMELINE_H_
#define TIMELINE_H_

#include <libmy/collections/vec.h>
#include <SFML/Graphics.h>

#include "Rpg/Entities/entity.h"

#define TURN_TIME 30.0
#define FRAME_WIDTH 65.0
#define FRAME_SPACING 5.0
#define CIRCLE_RADIUS 50

struct fight_t;

typedef struct frame {
    sfRectangleShape *entity_rect;
    sfRectangleShape *bg;
    sfRectangleShape *life_bar;
    entity_t *entity;
} frame_t;

typedef struct playing_bubble {
    sfCircleShape *circle;
    sfText *text_pa;
    sfText *text_pm;
    entity_t *last_entity;
} playing_bubble_t;

typedef struct timeline {
    sfView *view;
    struct fight_t *fight;
    float time_past;
    int current;
    sfRectangleShape *time_rect;
    int grabbed;
    sfVector2i last_pos;
    playing_bubble_t bubble;
    /// vector of frame_t
    my_vec_t frames;
} timeline_t;

void frame_init(frame_t *frame, entity_t *entity, int id);
void frame_update(frame_t *frame);
void frame_update_id(frame_t *frame, int new_id);
void frame_set_playing(frame_t *frame, int playing);
void frame_draw(frame_t *frame, sfRenderWindow *window);
void frame_destroy(frame_t *frame);

void playing_bubble_init(playing_bubble_t *bubble, sfFont *font);
void playing_bubble_update(playing_bubble_t *bubble, entity_t *entity);
void playing_bubble_draw(playing_bubble_t *bubble, sfRenderWindow *window);
void playing_bubble_destroy(playing_bubble_t *bubble);

void timeline_init(timeline_t *timeline, struct fight_t *fight);
void timeline_update_time(timeline_t *timeline, float dt);
void timeline_update(timeline_t *timeline, float dt);
void timeline_handle_events(timeline_t *timeline, sfEvent *event);
int timeline_get_entity_id(timeline_t *timeline, entity_t *entity);
void timeline_new_turn(timeline_t *timeline, entity_t *playing_entity);
void timeline_remove_entity(timeline_t *timeline, entity_t *entity);
void timeline_draw(timeline_t *timeline, sfRenderWindow *window);
void timeline_destroy(timeline_t *timeline);

#endif /* !TIMELINE_H_ */