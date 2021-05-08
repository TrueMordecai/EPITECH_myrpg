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

struct rpg_t;

typedef struct general_ui_s {
    struct rpg_t *rpg;
    sfSprite *qst_button;;
    sfSprite *inv_button;
    sfTexture *button_texture;
}general_ui_t;

#endif
