/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** main loop of my hunter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rpg/rpg.h"

static inline bool is_scrolling_deep(inventory_t *inv, unsigned int i)
{
    return (
        (bool)((i < (unsigned int)40 + inv->scroll * 4) && (inv->scroll < 39)));
}

static inline int get_scroll(rpg_t *g)
{
    return (int)(g->inventory.scroll * 4);
}

extern void item_clicked(rpg_t *game, item_t *item, sfVector2f pos)
{
    item_t tmp;
    if (sprite_is_hover(game->inventory.sprite, pos)
        && game->inventory.mouse_left == PRESS && item->name
        && game->inventory.item_selected.name != NULL) {
        rpg_copy_item(&tmp, game->inventory.item_selected);
        rpg_destroy_item(&game->inventory.item_selected);
        rpg_copy_item(&game->inventory.item_selected, *item);
        rpg_copy_item(item, tmp);
        rpg_destroy_item(&tmp);
        return;
    }
    if (sprite_is_hover(game->inventory.sprite, pos)
        && game->inventory.mouse_left == PRESS && item->name) {
        rpg_copy_item(&game->inventory.item_selected, *item);
        rpg_destroy_item(item);
        game->inventory.mouse_left = HOLD;
    }
}

static void rpg_inventory_draw_items_move_sprite(
    float sl, sfVector2f *pos, sfSprite *s)
{
    pos->x++;
    if (pos->x == 4) {
        sfSprite_move(s, (sfVector2f){(-320 + 64) * sl, 64 * sl});
        pos->x = 0;
        pos->y++;
    }
}

extern void rpg_inventory_draw_items(rpg_t *g)
{
    int save = -1;
    sfVector2f pos = (sfVector2f){0, 0};

    sfSprite_setPosition(g->inventory.sprite, (sfVector2f){0, 0});
    for (int i = get_scroll(g); is_scrolling_deep(&g->inventory, i); i++) {
        if (g->inventory.items[i].name != NULL) {
            set_item_texture_rect(g->inventory.sprite, &g->inventory.items[i]);
            sfRenderWindow_drawSprite(g->wind, g->inventory.sprite, NULL);
        }
        if (sprite_is_hover(g->inventory.sprite, get_mouse_pos_vec2f(g->wind)))
            save = i;
        item_clicked(g, &g->inventory.items[i], get_mouse_pos_vec2f(g->wind));
        sfSprite_move(g->inventory.sprite, (sfVector2f){64 * SL(g), 0});
        rpg_inventory_draw_items_move_sprite(SL(g), &pos, g->inventory.sprite);
    }
    if (save != -1)
        rpg_inventory_draw_items_tooltip(g, &g->inventory.items[save]);
}
