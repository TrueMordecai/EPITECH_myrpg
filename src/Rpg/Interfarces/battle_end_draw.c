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

static item_rarity_t random_rarity()
{
    item_rarity_t r = rand() % 100;

    if (r >= 0 && r < 39)
        return (COMMON);
    if (r >= 40 && r < 69)
        return (UNCOMMON);
    if (r >= 70 && r < 85)
        return (RARE);
    if (r >= 89 && r < 95)
        return (EPIC);
    return (LEGENDARY);
}

extern void battle_end_draw(rpg_t *r)
{
    int level = r->battle_end.average_level - 1;

    if (!r->battle_end.is_on)
        return;
    if (level <= 0)
        level = 1;
    if (!r->battle_end.is_item_add && r->battle_end.is_win) {
        r->battle_end.item_to_add = rpg_create_item(level, random_rarity());
        set_item_texture_rect(r->battle_end.item_sprite, &r->battle_end.item_to_add);
        rpg_add_item_to_inventory(r, r->battle_end.item_to_add);
        r->battle_end.is_item_add = true;
    }
    sfRenderWindow_drawSprite(r->wind, r->battle_end.menu_sprite, NULL);
    if (r->battle_end.is_win) {
        if (sprite_is_hover(r->battle_end.item_sprite, get_mouse_pos_vec2f(r->wind)))
            rpg_inventory_draw_items_tooltip(r, &r->battle_end.item_to_add);
        sfRenderWindow_drawSprite(r->wind , r->battle_end.item_sprite, NULL);
    }
}
