/*
** EPITECH PROJECT, 2021
** Game Engine
** File description:
** asset manager functions
*/

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Texture.h>
#include <stdalign.h>

#include "functions.h"
#include "GameEngine/asset_manager.h"

static const my_map_kvtypes_t FONTS_KVTYPES = {
    .key_size = sizeof(char *),
    .key_align = alignof(char *),
    .value_size = sizeof(asset_t),
    .value_align = alignof(asset_t),
    .hash = MY_HASH_MAP_CSTR_HASH,
    .compare = MY_HASH_MAP_CSTR_CMP,
    .value_drop = (my_map_drop_t)&font_asset_drop,
};

static const my_map_kvtypes_t TEXTURES_KVTYPES = {
    .key_size = sizeof(char *),
    .key_align = alignof(char *),
    .value_size = sizeof(asset_t),
    .value_align = alignof(asset_t),
    .hash = MY_HASH_MAP_CSTR_HASH,
    .compare = MY_HASH_MAP_CSTR_CMP,
    .value_drop = (my_map_drop_t)&texture_asset_drop,
};

void asset_manager_init(asset_manager_t *asset_manager)
{
    my_hash_map_init(&asset_manager->fonts, &FONTS_KVTYPES);
    my_hash_map_init(&asset_manager->textures, &TEXTURES_KVTYPES);
    load_all_textures(asset_manager);
}

void load_texture(asset_manager_t *asset_manager, char const *name,
    char const *filepath, int smooth)
{
    asset_t asset;

    if (my_hash_map_contains(&asset_manager->textures, &name))
        return;
    asset.texture = sfTexture_createFromFile(filepath, NULL);
    if (asset.texture == NULL)
        return;
    sfTexture_setSmooth(asset.texture, smooth);
    my_hash_map_insert(&asset_manager->textures, &name, &asset);
}

void load_font(
    asset_manager_t *asset_manager, char const *name, char const *filepath)
{
    asset_t asset;

    if (my_hash_map_contains(&asset_manager->textures, &name))
        return;
    asset.font = sfFont_createFromFile(filepath);
    if (asset.font == NULL)
        return;
    my_hash_map_insert(&asset_manager->fonts, &name, &asset);
}

sfTexture *get_texture(asset_manager_t *asset_manager, char const *name)
{
    asset_t *asset = my_hash_map_get(&asset_manager->textures, &name);

    return asset == NULL ? NULL : asset->texture;
}

sfFont *get_font(asset_manager_t *asset_manager, char const *name)
{
    asset_t *asset = my_hash_map_get(&asset_manager->fonts, &name);

    return asset == NULL ? NULL : asset->font;
}
