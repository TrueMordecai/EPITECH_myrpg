/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** init game
*/

#include "Rpg/rpg.h"
#include <stdio.h>
#include <string.h>
#include "dirent.h"

item_t inventory_init_blanck_item(void)
{
    item_t i;

    i.earth = 0;
    i.elem = 0;
    i.fire = 0;
    i.level = 0;
    i.life = 0;
    i.name = NULL;
    i.rarity = 0;
    i.res_earth = 0;
    i.res_water = 0;
    i.res_wind = 0;
    i.res_fire = 0;
    i.water = 0;
    i.wind = 0;
    return (i);
}

static void inventory_init_2(inventory_t *inv)
{
    sfText_setColor(inv->text, sfWhite);
    sfText_setCharacterSize(inv->text, 37);
    inv->equipement = malloc(sizeof(item_t) * 4);
    for (int i = 0; i != 4; i++)
        inv->equipement[i] = rpg_create_blank_item();
    inv->container = sfSprite_create();
    sfSprite_setTexture(inv->container, inv->ui_int_texture , sfFalse);
    sfSprite_setTextureRect(inv->container, (sfIntRect){0, 0, 16, 16});
    sfSprite_setScale(inv->container, (sfVector2f){4, 4});
    inv->tooltip = sfSprite_create();
    inv->texture_tooltip = sfTexture_createFromFile("assets/Inventory/items_tooltip.png", 0);
    sfSprite_setTexture(inv->tooltip, inv->texture_tooltip, sfFalse);
    sfSprite_setScale(inv->tooltip, (sfVector2f){9, 9});
    inv->stat_text = sfText_create();
    inv->stat_font = sfFont_createFromFile("./assets/Fonts/pixel.ttf");
    sfText_setFont(inv->stat_text, inv->stat_font);
    sfText_setCharacterSize(inv->stat_text, 30);
    sfText_setColor(inv->stat_text, sfWhite);
    inv->is_open = false;
    inv->item_selected = rpg_create_blank_item();
}

extern inventory_t inventory_init(void)
{
    inventory_t i;

    i.scroll = 0;
    i.sprite = sfSprite_create();
    i.texture = sfTexture_createFromFile("assets/Inventory/items_sheet.png", 0);
    i.items = malloc(sizeof(item_t) * 200);
    for (uint j = 0; j != 200; j++)
        i.items[j] = rpg_create_blank_item();
    i.ui_inventory = sfSprite_create();
    i.ui_int_texture = sfTexture_createFromFile
        ("assets/Inventory/inventory_menu.png", 0);
    sfSprite_setScale(i.ui_inventory, (sfVector2f){4, 4});
    sfSprite_setTexture(i.ui_inventory, i.ui_int_texture, sfFalse);
    sfSprite_setTexture(i.sprite, i.texture, sfFalse);
    sfSprite_setTextureRect(i.sprite, (sfIntRect){0, 0, 16, 16});
    sfSprite_setScale(i.sprite, (sfVector2f){4, 4});
    i.text = sfText_create();
    i.font = sfFont_createFromFile("./assets/Fonts/pixel.ttf");
    sfText_setFont(i.text, i.font);
    inventory_init_2(&i);
    return (i);
}