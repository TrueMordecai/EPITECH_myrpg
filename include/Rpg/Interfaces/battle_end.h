/*
** EPITECH PROJECT, 2020
** my_hunter include
** File description:
** all information for the my _hunter
*/

#ifndef _BATTLE_END_UI_H_
#define _BATTLE_END_UI_H_
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
#include "Rpg/Interfaces/inventory.h"

struct rpg;
struct item_t;
struct battle_t;

typedef struct battle_end_s {
    rpg_t *rpg;
    sfSprite *menu_sprite;
    sfTexture *menu_texture;
    sfSprite *item_sprite;
    item_t item_to_add;
    unsigned int average_level;
    unsigned int enemy_number;
    bool is_on;
    bool is_win;
    bool is_item_add;
}battle_end_t;
extern battle_end_t battle_end_init(rpg_t *rpg);
extern void battle_end_draw(rpg_t *rpg);
extern void battle_end_setup(struct battle_t *battle);
#endif
