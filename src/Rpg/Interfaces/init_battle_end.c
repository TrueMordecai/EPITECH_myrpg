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
#include "Rpg/Interfaces/battle_end.h"

extern battle_end_t battle_end_init(rpg_t *rpg)
{
    battle_end_t b;

    b.rpg = rpg;
    b.menu_sprite = sfSprite_create();
    b.menu_texture = get_texture(&rpg->state->game_data->assets, "b_end");
    sfSprite_setTexture(b.menu_sprite, b.menu_texture, sfFalse);
    sfSprite_setScale(b.menu_sprite, (sfVector2f){6 * SL(rpg), 6 * SL(rpg)});
    sfSprite_setPosition(
        b.menu_sprite, (sfVector2f){624 * SL(rpg), 150 * SL(rpg)});
    b.item_sprite = sfSprite_create();
    sfSprite_setTexture(b.item_sprite, rpg->inventory.texture, sfFalse);
    sfSprite_setPosition(
        b.item_sprite, (sfVector2f){912 * SL(rpg), 345 * SL(rpg)});
    sfSprite_setScale(b.item_sprite, (sfVector2f){4 * SL(rpg), 4 * SL(rpg)});
    b.is_on = false;
    b.is_win = false;
    b.is_item_add = false;
    b.average_level = 0;
    b.item_to_add = rpg_create_blank_item();
    return (b);
}
