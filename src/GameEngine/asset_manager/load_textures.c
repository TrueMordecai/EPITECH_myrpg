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
}

void load_all_textures(asset_manager_t *manager)
{
    load_texture(manager, "atlas", "assets/Textures/tileset.png");
    load_texture(manager, "buttons", "assets/Textures/buttons.png");
    load_fonts(manager);
}
