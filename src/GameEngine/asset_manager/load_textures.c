/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** load textures
*/

#include "GameEngine/game_head.h"

static void load_fonts(asset_manager_t *manager)
{
    //load_font(manager, "roboto_font", "assets/Fonts/fontname.ttf");
}

void load_all_textures(asset_manager_t *manager)
{
    load_texture(manager, "atlas", "assets/Textures/tileset.png");
    load_fonts(manager);
}
