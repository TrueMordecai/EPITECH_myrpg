/*
** EPITECH PROJECT, 2021
** Game Engine
** File description:
** The asset manager
*/

#ifndef GE_ASSET_MANAGER_H
#define GE_ASSET_MANAGER_H

#include <SFML/Graphics/Types.h>
#include <libmy/collections/hash_map.h>

#include "types.h"

union asset {
    sfTexture *texture;
    sfFont *font;
};

struct asset_manager {
    my_hash_map_t fonts;
    my_hash_map_t textures;
};

void asset_manager_init(asset_manager_t *asset_manager);
/// Uninitializes the asset manager, but does not free the passed pointer.
void asset_manager_drop(asset_manager_t *manager);

void load_all_textures(asset_manager_t *manager);

void load_texture(asset_manager_t *asset_manager, char const *name,
    char const *filepath, int smooth);
struct sfTexture *get_texture(asset_manager_t *asset_manager, char const *name);

void load_font(
    asset_manager_t *asset_manager, char const *name, char const *filepath);
struct sfFont *get_font(asset_manager_t *asset_manager, char const *name);

/// Frees the inner @c sfFont of an asset, for use inside the fonts map of
/// @ref asset_manager_t.
void font_asset_drop(asset_t *asset);

/// Frees the inner @c sfTexture of an asset, for use inside the textures map
/// of @ref asset_manager_t.
void texture_asset_drop(asset_t *asset);

#endif
