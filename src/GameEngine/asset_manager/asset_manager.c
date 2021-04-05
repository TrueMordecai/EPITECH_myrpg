/*
** EPITECH PROJECT, 2020
** GameEngine
** File description:
** asset manager functions
*/

#include "GameEngine/game_head.h"
#include "functions.h"

void init_asset_manager(asset_manager_t *asset_manager)
{
    asset_manager->fonts = my_map(char *, asset_t *, my_map_strcmp, 0, 1);
    asset_manager->textures = my_map(char *, asset_t *, my_map_strcmp, 0, 1);
    load_all_textures(asset_manager);
}

void load_texture(asset_manager_t *asset_manager, char const *name, \
char const *filepath)
{
    asset_t *elmt = (asset_t *)my_map_find(asset_manager->textures, \
    (size_t)name);
    sfTexture *texture;
    asset_t *asset;

    if (elmt != 0){
        return;
    }
    texture = sfTexture_createFromFile(filepath, NULL);
    if (texture == NULL)
        return;
    sfTexture_setSmooth(texture, 1);
    asset = malloc(sizeof(asset_t));
    asset->texture = texture;
    my_map_insert(asset_manager->textures, (size_t)name, (size_t)asset);
}

void load_font(asset_manager_t *asset_manager, char const *name, \
char const *filepath)
{
    asset_t *elmt = (asset_t *)my_map_find(asset_manager->fonts, (size_t)name);
    sfFont *font;
    asset_t *asset;

    if (elmt != NULL)
        return;
    font = sfFont_createFromFile(filepath);
    if (font == NULL)
        return;
    asset = malloc(sizeof(asset_t));
    asset->font = font;
    my_map_insert(asset_manager->fonts, (size_t)name, (size_t)asset);
}

sfTexture *get_texture(asset_manager_t *asset_manager, char const *name)
{
    asset_t *elmt = (asset_t *)my_map_find(asset_manager->textures, \
    (size_t)name);

    if (elmt == NULL)
        return NULL;
    return elmt->texture;
}

sfFont *get_font(asset_manager_t *asset_manager, char const *name)
{
    asset_t *elmt = (asset_t *)my_map_find(asset_manager->fonts, (size_t)name);

    if (elmt == NULL)
        return NULL;
    return elmt->font;
}