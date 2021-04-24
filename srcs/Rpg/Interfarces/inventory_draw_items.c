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

static inline bool is_scrolling_deep(inventory_t *inv, unsigned int i)
{
    return ((bool)((i < (unsigned int)40
                   + inv->scroll * 4) && (inv->scroll < 39)));
}

static inline int get_scroll(rpg_t *g)
{
    return (int)(g->inventory.scroll * 4);
}

extern void item_clicked(rpg_t *game, item_t *item, sfVector2f pos)
{
    if (sprite_is_hover(game->inventory.sprite, pos) && sfMouse_isButtonPressed(sfMouseLeft) && item->name != NULL) {
        rpg_copy_item(&game->inventory.item_selected, *item);
        rpg_destroy_item(item);
    }
}

extern void rpg_inventory_draw_items(rpg_t *game)
{
    int save = -1;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->wind);
    sfVector2f new_vec = {vec.x, vec.y};
    sfVector2f pos = (sfVector2f){0, 0};

    sfSprite_setPosition(game->inventory.sprite, (sfVector2f){0, 0});
    for (int i = get_scroll(game); is_scrolling_deep(&game->inventory, i);i++) {
        if (game->inventory.items[i].name != NULL) {
            set_item_texture_rect(game->inventory.sprite, &game->inventory.items[i]);
            sfRenderWindow_drawSprite(game->wind, game->inventory.sprite, NULL);
        }
        if (sprite_is_hover(game->inventory.sprite, new_vec))
            save = i;
        item_clicked(game, &game->inventory.items[i], new_vec);
        sfSprite_move(game->inventory.sprite, (sfVector2f){64, 0});
        pos.x++;
        if (pos.x == 4) {
            sfSprite_move(game->inventory.sprite, (sfVector2f){-320 + 64, 64});
            pos.x = 0;
            pos.y++;
        }
    }
    if (save != -1)
        rpg_inventory_draw_items_tooltip(game, &game->inventory.items[save]);
}
