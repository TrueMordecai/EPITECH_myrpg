/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** layer
*/

#ifndef LAYER_H
#define LAYER_H

#include <SFML/Graphics.h>

typedef struct layer_t {
    int tiles_size;
    sfVector2i size;
    sfVector2i pos;
    sfRectangleShape **tiles;
    sfTexture *tex;
    sfView *view;
} layer_t;

layer_t *layer_create(sfView *view, sfTexture *tex, int tiles_size);
void layer_init(layer_t *layer, sfVector2i size, sfVector2i pos);
void layer_place_tile(layer_t *layer, sfVector2i pos, int tile);
void layer_draw(layer_t *layer, sfRenderWindow *wind, \
sfVector2i min, sfVector2i max);
void layer_destroy(layer_t *layer);

extern const int TILE_SIZE;
extern const int SET_WIDTH;
extern const int SET_HEIGHT;

#endif /* !LAYER_H */