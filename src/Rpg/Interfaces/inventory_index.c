/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Random functions releated to the inventory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rpg/rpg.h"

extern void rpg_inventory_draw(rpg_t *game)
{
    rpg_inventory_mouse_input(game);
    if (game->inventory.is_open) {
        sfRenderWindow_drawSprite(game->wind, game->inventory.ui_inventory, 0);
        rpg_draw_equipement(game);
        rpg_inventory_draw_items(game);
        rpg_inventory_draw_cursor(game);
        rpg_inventory_clean_cursor(game);
    }
}

extern void rpg_add_item_to_inventory(rpg_t *game, item_t item)
{
    unsigned int i = 0;

    while (game->inventory.items[i].name)
        i++;
    game->inventory.items[i] = item;
}

extern void destroy_inventory(rpg_t *game)
{
    for (unsigned i = 0; i < 200; i++) {
        free(game->inventory.items[i].name);
    }
    free(game->inventory.items);
    for (unsigned i = 0; i < 4; i++) {
        free(game->inventory.equipement[i].name);
    }
    free(game->inventory.equipement);
    sfSprite_destroy(game->inventory.sprite);
    sfSprite_destroy(game->inventory.ui_inventory);
    sfSprite_destroy(game->inventory.container);
    sfSprite_destroy(game->inventory.tooltip);
    sfText_destroy(game->inventory.text);
    sfText_destroy(game->inventory.stat_text);
}
