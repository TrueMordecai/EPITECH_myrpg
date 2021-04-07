/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Asset manager struct
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

void init_asset_manager(asset_manager_t *asset_manager);
void load_all_textures(asset_manager_t *manager);
void asset_manager_destroy(asset_manager_t **assets);

void load_texture(
    asset_manager_t *asset_manager, char const *name, char const *filepath);
struct sfTexture *get_texture(
    asset_manager_t *asset_manager, char const *name);

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
