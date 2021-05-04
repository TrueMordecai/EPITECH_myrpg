/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** load textures
*/

#include "GameEngine/asset_manager.h"

static void load_fonts(asset_manager_t *manager)
{
    load_font(manager, "roboto_font", "assets/Fonts/roboto_regular.ttf");
    load_font(manager, "pixel", "assets/Fonts/pixel.ttf");
    load_font(manager, "pixel2", "assets/Fonts/pixel2.ttf");
}

void load_all_textures(asset_manager_t *manager)
{
    load_texture(
        manager, "items_tooltip", "assets/Inventory/items_tooltip.png", 0);
    load_texture(
        manager, "inv_menu", "assets/Inventory/inventory_menu.png", 0);
    load_texture(manager, "item_sheet", "assets/Inventory/items_sheet.png", 0);
    load_texture(manager, "atlas", "assets/Textures/tileset.png", 0);
    load_texture(manager, "buttons", "assets/Textures/buttons.png", 1);
    load_texture(manager, "turn_pass", "assets/Textures/turn_pass.png", 0);
    load_texture(manager, "spells", "assets/Textures/spells.png", 0);
    load_texture(
        manager, "Knight", "assets/Textures/Characters/Knight.png", 0);
    load_texture(
        manager, "Skeleton", "assets/Textures/Characters/skeleton.png", 0);
    load_texture(
        manager, "Green Man", "assets/Textures/Characters/Greenman.png", 0);
    load_fonts(manager);
}
