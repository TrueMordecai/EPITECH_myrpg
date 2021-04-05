/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game Engine - destroy asset manager
*/

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Texture.h>
#include <libmy/memory/alloc.h>
#include <GameEngine/asset_manager.h>

void asset_manager_destroy(asset_manager_t **assets)
{
    my_hash_map_drop(&(*assets)->fonts);
    my_hash_map_drop(&(*assets)->textures);
    my_sfree((void **)assets);
}

void font_asset_drop(asset_t *asset)
{
    if (asset->font == NULL) {
        sfFont_destroy(asset->font);
        asset->font = NULL;
    }
}

void texture_asset_drop(asset_t *asset)
{
    if (asset->texture == NULL) {
        sfTexture_destroy(asset->texture);
        asset->texture = NULL;
    }
}
