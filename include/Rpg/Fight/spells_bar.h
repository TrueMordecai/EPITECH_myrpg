/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spells_bar
*/

#ifndef SPELLS_BAR_H_
#define SPELLS_BAR_H_

#include <SFML/Graphics.h>
#include <libmy/collections/vec.h>

#define SPELLS_BAR_WIDTH 6
#define SPELLS_BAR_HEIGHT 2

struct fight_t;
struct entity_t;

typedef struct spells_bar {
    sfText *text_pa;
    sfText *text_pm;
    sfRectangleShape *life;
    sfRectangleShape *life_bg;
    struct entity_t *last_entity;
    int current_hovered;
    float time_hovered;
    int current_frame;
    int grabbed;
    sfView *view;
    sfVector2i last_pos;
    sfRectangleShape *background;
    sfRectangleShape *move_bar;
    struct fight_t *fight;
    int nb_frames;
    sfRectangleShape **frames;
} spells_bar_t;

void spells_bar_init(spells_bar_t *bar, struct fight_t *fight);
void spells_bar_draw(spells_bar_t *bar, sfRenderWindow *window);
int spells_bar_handle_events(spells_bar_t *bar, sfEvent *event);
int spells_bar_handle_move(
    spells_bar_t *bar, sfEvent *event, sfRenderWindow *window);
void spells_bar_update_outlines(spells_bar_t *bar);
void spells_bar_update_spells(spells_bar_t *bar);
int spells_bar_get_hovered(spells_bar_t *bar);
void spells_bar_update(spells_bar_t *bar, struct entity_t *entity, float dt);
void spells_bar_new_turn(spells_bar_t *bar);
void spells_bar_set_selected(spells_bar_t *bar, int selected);
void spells_bar_update_entity_spell(spells_bar_t *bar);
void spells_bar_destroy(spells_bar_t *bar);

#endif /* !SPELLS_BAR_H_ */