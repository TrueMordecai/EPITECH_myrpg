/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game Engine - uninitializes the asset manager
*/

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Texture.h>
#include <GameEngine/asset_manager.h>

void asset_manager_drop(asset_manager_t *manager)
{
    my_hash_map_drop(&manager->fonts);
    my_hash_map_drop(&manager->textures);
}

void font_asset_drop(asset_t *asset)
{
    if (asset->font != NULL) {
        sfFont_destroy(asset->font);
        asset->font = NULL;
    }
}

void texture_asset_drop(asset_t *asset)
{
    if (asset->texture != NULL) {
        sfTexture_destroy(asset->texture);
        asset->texture = NULL;
    }
}
