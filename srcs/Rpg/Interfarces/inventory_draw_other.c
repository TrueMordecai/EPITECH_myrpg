/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main loop of my hunter
*/

#include "Rpg/rpg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void rpg_inventory_draw_cursor(rpg_t *g)
{
    sfVector2i v = sfMouse_getPositionRenderWindow(g->wind);

    if (g->inventory.item_selected.name == NULL)
        return;
    set_item_texture_rect(g->inventory.sprite, &g->inventory.item_selected);
    sfSprite_setPosition(g->inventory.sprite, (sfVector2f){v.x, v.y});
    sfRenderWindow_drawSprite(g->wind, g->inventory.sprite, NULL);
}

extern void rpg_draw_equipement(rpg_t *game)
{
    int save = -1;
    for (unsigned int i = 0; i != 4; i++) {
        sfSprite_setPosition(game->inventory.container, (sfVector2f){320 + i * 64, 320});
        sfSprite_setPosition(game->inventory.sprite, (sfVector2f){320 + i * 64, 320});
        sfRenderWindow_drawSprite(game->wind, game->inventory.container, NULL);
        if (sprite_is_hover(game->inventory.container, get_mouse_pos_vec2f(game->wind)) && sfMouse_isButtonPressed(sfMouseLeft) && game->inventory.item_selected.name != NULL) {
            rpg_copy_item(&game->inventory.equipement[i], game->inventory.item_selected);
            rpg_destroy_item(&game->inventory.item_selected);
            game->inventory.item_selected.name = NULL;
        }
        if (game->inventory.equipement[i].name != NULL) {
            set_item_texture_rect(game->inventory.sprite, &game->inventory.equipement[i]);
            sfRenderWindow_drawSprite(game->wind, game->inventory.sprite, NULL);
        }
        if (sprite_is_hover(game->inventory.container, get_mouse_pos_vec2f(game->wind)))
            save = i;
    }
    if (save != -1 && game->inventory.equipement[save].name != NULL)
        rpg_inventory_draw_items_tooltip(game, &game->inventory.equipement[save]);
}

extern void rpg_inventory_clean_cursor(rpg_t *game)
{
    if (game->inventory.mouse_left == PRESS && game->inventory.item_selected.name != NULL) {
        rpg_add_item_to_inventory(game, game->inventory.item_selected);
        game->inventory.item_selected.name = NULL;
    }
}
