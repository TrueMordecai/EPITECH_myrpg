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

static inline bool is(sfSprite *s, rpg_t *game)
{
    if (sprite_is_hover(s, get_mouse_pos_vec2f(game->wind)) &&
        game->inventory.mouse_left == PRESS)
        return (true);
    return (false);
}

extern void rpg_inventory_draw_cursor(rpg_t *g)
{
    sfVector2i v = sfMouse_getPositionRenderWindow(g->wind);

    if (g->inventory.item_selected.name == NULL)
        return;
    set_item_texture_rect(g->inventory.sprite, &g->inventory.item_selected);
    sfSprite_setPosition(g->inventory.sprite, (sfVector2f){v.x, v.y});
    sfRenderWindow_drawSprite(g->wind, g->inventory.sprite, NULL);
}

static void rpg_draw_equipemnt_on_click_behaviour(rpg_t *g, unsigned int i)
{
    item_t tmp;
    char *sel_name = g->inventory.item_selected.name;
    char *eq_name = g->inventory.equipement[i].name;

    if (is(g->inventory.container, g) && sel_name && eq_name) {
        rpg_copy_item(&tmp, g->inventory.item_selected);
        rpg_destroy_item(&g->inventory.item_selected);
        rpg_copy_item(&g->inventory.item_selected, g->inventory.equipement[i]);
        rpg_copy_item(&g->inventory.equipement[i], tmp);
        rpg_destroy_item(&tmp);
    }
    if (is(g->inventory.container, g) && !sel_name && eq_name) {
        rpg_copy_item(&g->inventory.item_selected, g->inventory.equipement[i]);
        rpg_destroy_item(&g->inventory.equipement[i]);
        g->inventory.mouse_left = HOLD;
    }
    if (is(g->inventory.container, g) && sel_name && !eq_name) {
        rpg_copy_item(&g->inventory.equipement[i], g->inventory.item_selected);
        rpg_destroy_item(&g->inventory.item_selected);
        g->inventory.item_selected.name = NULL;
    }
}

extern void rpg_draw_equipement(rpg_t *g)
{
    int tooltip = -1;

    for (unsigned int i = 0; i != 4; i++) {
        sfSprite_setPosition(g->inventory.container, (sfVector2f){320 + i * 64,
                    320});
        sfSprite_setPosition(g->inventory.sprite, (sfVector2f){320 + i * 64,
                    320});
        sfRenderWindow_drawSprite(g->wind, g->inventory.container, NULL);
        rpg_draw_equipemnt_on_click_behaviour(g, i);
        if (g->inventory.equipement[i].name != NULL) {
            set_item_texture_rect(g->inventory.sprite,
                                  &g->inventory.equipement[i]);
            sfRenderWindow_drawSprite(g->wind, g->inventory.sprite, NULL);
        }
        if (sprite_is_hover(g->inventory.container,
                            get_mouse_pos_vec2f(g->wind)))
            tooltip = i;
    }
    if (tooltip != -1 && g->inventory.equipement[tooltip].name != NULL)
        rpg_inventory_draw_items_tooltip(g, &g->inventory.equipement[tooltip]);
}

extern void rpg_inventory_clean_cursor(rpg_t *g)
{
    if (g->inventory.mouse_left == PRESS && g->inventory.item_selected.name) {
        rpg_add_item_to_inventory(g, g->inventory.item_selected);
        g->inventory.item_selected.name = NULL;
    }
}
