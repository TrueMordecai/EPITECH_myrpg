/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Create items
*/

#include "Rpg/rpg.h"

extern item_t rpg_create_blank_item(void)
{
    item_t new;

    new.earth = 0;
    new.fire = 0;
    new.water = 0;
    new.wind = 0;
    new.level = 0;
    new.life = 0;
    new.name = NULL;
    new.rarity = 0;
    new.res_fire = 0;
    new.res_water = 0;
    new.res_earth = 0;
    new.res_wind = 0;
    return (new);
}

static void rpg_create_item_add_offense(
    item_t *item, unsigned char level, bool apply_element)
{
    int i = rand() % 4;
    int formula_res = rand() % (level * 2) + (level * 2);

    if (apply_element)
        item->elem = i;
    if (i == 0)
        item->earth += formula_res;
    if (i == 1)
        item->fire += formula_res;
    if (i == 2)
        item->water += formula_res;
    if (i == 3)
        item->wind += formula_res;
}

static void rpg_create_item_add_life(item_t *item, unsigned char level)
{
    item->life = rand() % (level * 5) + rand() % (level * 5);
}

static void rpg_create_item_add_defense(item_t *item, unsigned char level)
{
    int i = rand() % 4;
    int formula_res = rand() % (level * 1) + (level * 2);

    if (i == 0)
        item->res_earth = formula_res;
    if (i == 1)
        item->res_fire = formula_res;
    if (i == 2)
        item->res_water = formula_res;
    if (i == 3)
        item->res_wind = formula_res;
}

extern item_t rpg_create_item(unsigned char level, item_rarity_t rarity)
{
    item_t item = rpg_create_blank_item();

    item.rarity = rarity;
    item.level = level;
    if (rarity >= COMMON)
        rpg_create_item_add_offense(&item, level, true);
    if (rarity >= UNCOMMON)
        rpg_create_item_add_defense(&item, level);
    if (rarity >= RARE)
        rpg_create_item_add_life(&item, level);
    if (rarity >= EPIC)
        rpg_create_item_add_offense(&item, level, false);
    if (rarity >= LEGENDARY)
        rpg_create_item_add_defense(&item, level);
    rpg_create_item_name_generator(&item, level);
    return (item);
}
