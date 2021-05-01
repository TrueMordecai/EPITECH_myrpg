/*
** EPITECH PROJECT, 2020
** my_hunter include
** File description:
** all information for the my _hunter
*/

#ifndef _INVENTORY_H_
#define _INVENTORY_H_
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <SFML/Graphics/Rect.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "Rpg/Entities/stats.h"
//#include "../rpg.h"

typedef enum {
    COMMON = 0,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY,
    ITEM_RARITY_LIMIT,
} item_rarity_t;

typedef enum {
    NOTHING = 0,
    PRESS = 1,
    HOLD = 2
} key_state;

typedef struct item_s {
    char *name;
    unsigned char level;
    item_rarity_t rarity;
    enum elements elem;
    unsigned char life;
    unsigned char water;
    unsigned char wind;
    unsigned char fire;
    unsigned char earth;
    unsigned char res_water;
    unsigned char res_wind;
    unsigned char res_fire;
    unsigned char res_earth;
} item_t;

typedef struct inventory_s {
    item_t *items;
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    sfFont *font;
    sfText *stat_text;
    sfFont *stat_font;
    sfSprite *tooltip;
    sfTexture *texture_tooltip;
    int scroll;
    sfSprite *ui_inventory;
    sfTexture *ui_int_texture;
    sfBool is_open;
    item_t item_selected;
    item_t *equipement;
    sfSprite *container;
    key_state mouse_left;
}inventory_t;

extern item_t rpg_create_blank_item();
extern item_t rpg_create_item(unsigned char level, item_rarity_t rarity);
item_t inventory_init_blanck_item(void);
extern inventory_t inventory_init(void);
extern void rpg_create_item_name_generator(item_t *item, int level);
extern sfVector2f get_mouse_pos_vec2f(sfRenderWindow *w);
extern void rpg_destroy_item(item_t *i);
extern void rpg_copy_item(item_t *d, item_t s);
extern bool sprite_is_hover(sfSprite *s, sfVector2f m_pos);
extern void rpg_inventory_draw_items_tooltip(struct rpg_t *game, item_t *item);
extern void rpg_inventory_draw_cursor(struct rpg_t *g);
extern void rpg_draw_equipement(struct rpg_t *game);
extern void rpg_inventory_clean_cursor(struct rpg_t *game);
extern void rpg_inventory_mouse_input(struct rpg_t *game);
extern void rpg_inventory_draw(struct rpg_t *game);
extern void rpg_add_item_to_inventory(struct rpg_t *game, item_t item);
extern void destroy_inventory(struct rpg_t *game);
extern void set_item_texture_rect(sfSprite *s, item_t *i);
extern void rpg_inventory_draw_items(struct rpg_t *game);
#endif
