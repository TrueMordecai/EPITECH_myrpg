/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** init game
*/

#include <stdio.h>
#include <string.h>
#include "Rpg/rpg.h"
#include "dirent.h"

extern battle_end_t battle_end_init(rpg_t *rpg)
{
    battle_end_t b;
    sfVector2u w_size = sfRenderWindow_getSize(rpg->wind);

    b.rpg = rpg;
    b.menu_sprite = sfSprite_create();
    b.menu_texture = get_texture(&rpg->state->game_data->assets, "b_end");
    sfSprite_setTexture(b.menu_sprite, b.menu_texture, sfFalse);
    sfSprite_setScale(b.menu_sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(b.menu_sprite, (sfVector2f){(w_size.x - 448) / 2, 99});
    b.item_sprite = sfSprite_create();
    sfSprite_setTexture(b.item_sprite, rpg->inventory.texture, sfFalse);
    sfSprite_setPosition(b.item_sprite, (sfVector2f){(w_size.x - 64) / 2, 230});
    sfSprite_setScale(b.item_sprite, (sfVector2f){4, 4});
    b.is_on = false;
    b.is_win = false;
    b.is_item_add = false;
    b.average_level = 0;
    b.enemy_number = 0;
    b.item_to_add = rpg_create_blank_item();
    return (b);
}
