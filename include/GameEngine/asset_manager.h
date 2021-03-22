/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Asset manager struct
*/

#ifndef GE_ASSET_MANAGER_H
#define GE_ASSET_MANAGER_H

typedef union {
    struct sfTexture *texture;
    struct sfFont *font;
} asset_t;

typedef struct asset_manager_t {
    struct my_map_t *fonts;
    struct my_map_t *textures;
} asset_manager_t;

void init_asset_manager(asset_manager_t *asset_manager);
void load_all_textures(asset_manager_t *manager);
void asset_manager_destroy(asset_manager_t **assets);

void load_texture(asset_manager_t *asset_manager, char const *name, \
char const *filepath);
struct sfTexture *get_texture(asset_manager_t *asset_manager, char const *name);

void load_font(asset_manager_t *asset_manager, char const *name, \
char const *filepath);
struct sfFont *get_font(asset_manager_t *asset_manager, char const *name);

#endif