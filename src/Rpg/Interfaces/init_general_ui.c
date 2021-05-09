/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** init game
*/

#include <stdio.h>
#include <string.h>
#include "Rpg/rpg.h"
#include "dirent.h"

extern inventory_t inventory_init(rpg_t *rpg)
{
    general_ui_t g;

    g.rpg = rpg;
    g.inv_button = sfSprite_create();
    g.qst_button = sfSprite_create();
    g.button_texture = get_texture(&rpg->state->game_data->assets, "gen_ui");
    sfSprite_setTexture(g.inv_button, inv->ui_int_texture, sfFalse);
    sfSprite_setTexture(g.qst_button, inv->ui_int_texture, sfFalse);
    sfSprite_setScale(g.inv_button, (sfVector2f){2, 2});
    sfSprite_setTextureRect(g.inv_button, (sfIntRect){64, 32});
    sfSprite_setScale(g.inv_button, (sfVector2f){})
    return (g);
}
