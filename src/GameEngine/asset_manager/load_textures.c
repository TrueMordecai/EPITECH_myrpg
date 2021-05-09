/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** load textures
*/

#include <SFML/Graphics.h>

#include "GameEngine/asset_manager.h"
#include "GameEngine/font_default.h"

#include "default_font.h"

static void init_pixels(sfUint32 *buffer)
{
    for (int x = 0; x < 16; x++)
        for (int y = 0; y < 16; y++)
            buffer[x + y * 32] = 0xff000000;
    for (int x = 16; x < 32; x++)
        for (int y = 0; y < 16; y++)
            buffer[x + y * 32] = 0xffdc00ff;
    for (int y = 16; y < 32; y++)
        for (int x = 0; x < 16; x++)
            buffer[x + y * 32] = 0xffdc00ff;
    for (int x = 16; x < 32; x++)
        for (int y = 16; y < 32; y++)
            buffer[x + y * 32] = 0xff000000;
}

sfTexture *get_null_texture(void)
{
    static sfTexture *err_texture = NULL;

    if (err_texture == NULL) {
        sfUint32 buffer[1024] = {0};
        sfImage *img;

        init_pixels(buffer);
        img = sfImage_createFromPixels(32, 32, (sfUint8 *)buffer);
        err_texture = sfTexture_createFromImage(img, NULL);
        sfTexture_setRepeated(err_texture, 1);
        sfImage_destroy(img);
    }
    return err_texture;
}

sfFont *get_null_font(void)
{
    static sfFont *err_font = NULL;

    if (err_font == NULL) {
        err_font = sfFont_createFromMemory(DEFAULT_FONT, DEFAULT_FONT_SIZE);
    }
    return err_font;
}

static void load_fonts(asset_manager_t *manager)
{
    load_font(manager, "roboto_font", "assets/Fonts/roboto_regular.ttf");
    load_font(manager, "pixel", "assets/Fonts/pixel.ttf");
    load_font(manager, "pixel2", "assets/Fonts/pixel2.ttf");
    get_null_font();
    load_texture(manager, "Dog", "assets/Textures/Characters/Dog.png", 0);
    load_texture(manager, "Lion", "assets/Textures/Characters/Lion.png", 0);
    load_texture(manager, "Frog", "assets/Textures/Characters/Frog.png", 0);
    load_texture(
        manager, "Mountain Master", "assets/Textures/Characters/Master.png", 0);
    load_texture(manager, "dialogue_bg", "assets/Textures/dialogue_bg.png", 0);
}

void load_all_textures(asset_manager_t *manager)
{
    load_texture(
        manager, "items_tooltip", "assets/Inventory/items_tooltip.png", 0);
    load_texture(manager, "inv_menu", "assets/Inventory/inventory_menu.png", 0);
    load_texture(manager, "menu_bg", "assets/Textures/menu_bg.jpeg", 0);
    load_texture(manager, "pause_bg", "assets/Textures/pause_bg.png", 0);
    load_texture(manager, "settings_bg", "assets/Textures/settings_bg.jpg", 0);
    load_texture(manager, "item_sheet", "assets/Inventory/items_sheet.png", 0);
    load_texture(manager, "atlas", "assets/Textures/tileset.png", 0);
    load_texture(manager, "buttons", "assets/Textures/buttons.png", 1);
    load_texture(manager, "turn_pass", "assets/Textures/turn_pass.png", 0);
    load_texture(manager, "spells", "assets/Textures/spells.png", 0);
    load_texture(manager, "Knight", "assets/Textures/Characters/Knight.png", 0);
    load_texture(
        manager, "Skeleton", "assets/Textures/Characters/Skeleton.png", 0);
    load_texture(
        manager, "Green Man", "assets/Textures/Characters/Greenman.png", 0);
    load_fonts(manager);
    get_null_texture();
}
