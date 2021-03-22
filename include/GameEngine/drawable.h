/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Drawables lists
*/

#ifndef GE_DRAWABLES_H
#define GE_DRAWABLES_H

struct sfRenderWindow;
struct sfRenderTexture;

typedef union {
    struct background_t *bg;
    struct sfText *text;
    struct sfRectangleShape *rect;
} drawable_t;

typedef struct draw_elmt_t{
    drawable_t *draw;
    unsigned char dtype;
} draw_elmt_t;

draw_elmt_t *create_data_d(drawable_t *draw, unsigned char dtype);
void delete_drawables(struct my_map_t *layer, int tag);
void destroy_drawable(draw_elmt_t *drawable);
void destroy_draw_layer(struct my_map_t *layer);

void draw_map(struct my_map_t *map, struct sfRenderWindow *wind);
void draw_vec(draw_elmt_t **vec, struct sfRenderWindow *wind);
void draw_map_texture(struct my_map_t *map, struct sfRenderTexture *texture);
void draw_vec_texture(draw_elmt_t **vec, struct sfRenderTexture *texture);

enum DRAWABLES_TYPES {D_TEXT, D_RECT, D_BG};

#endif