/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox
*/

#ifndef INFOBOX_H_
#define INFOBOX_H_

#include <SFML/Graphics.h>

#define INFO_WAIT 0.5f
enum infobox_type { INFOBOX_SPELL, INFOBOX_ENTITY };

struct rpg_t;

typedef struct infobox_base {
    sfView *view;
    sfRectangleShape *box;
    sfRectangleShape *icon;
    sfFont *font;
    sfVector2u window_size;
    sfVector2f box_size;
    struct rpg_t *rpg;
    enum infobox_type type;
} infobox_base_t;

infobox_base_t *infobox_create(
    struct rpg_t *rpg, enum infobox_type type, void *data, char *font_name);
infobox_base_t *infobox_recreate(
    enum infobox_type type, void *data, infobox_base_t *from);
void infobox_init(infobox_base_t *base, void *data);
void infobox_update(
    infobox_base_t **base_ptr, enum infobox_type type, void *data);
void infobox_change_type(
    infobox_base_t **base_ptr, enum infobox_type new_type, void *new_data);
void infobox_draw(infobox_base_t *base, sfRenderWindow *window);
void infobox_destroy(infobox_base_t *base);

void infobox_reset_box_size(infobox_base_t *base);
void infobox_set_box_size(
    infobox_base_t *base, sfVector2f new_size, int unmove_view);

void infobox_set_text_pos(sfText *text, sfVector3f pos);
void infobox_init_text(sfText *text, char const *format, sfVector3f pos, ...);
void infobox_create_text(
    infobox_base_t *base, sfText **text, sfColor color, int char_size);

#endif /* !INFOBOX_H_ */
