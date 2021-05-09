/*
** EPITECH PROJECT, 2021
** Game Engine
** File description:
** Drawable objects
*/

#ifndef GE_DRAWABLES_H
#define GE_DRAWABLES_H

#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <libmy/collections.h>

typedef enum {
    /// @ref drawable::data is of type @c sfText.
    D_TEXT,
    /// @ref drawable::data is of type @c sfRectangleShape.
    D_RECT,
    /// @ref drawable::data is of type @b [REDACTED].
    D_BG,
} drawable_type_t;

typedef struct drawable {
    union {
        sfText *text;
        sfRectangleShape *rect;
        /// unused ?
        struct background *bg;
        void *ptr;
    } data;
    /// This used to be an unsigned char, but because of structure alignment
    /// and padding rules, this wouldn't save any space.
    drawable_type_t dtype;
} drawable_t;

/// Creates a @ref drawable_t of type @c t with @c i as its data.
/// NOTE: the @c i pointer must be compatible with the given type.
#define DRAWABLE(i, t) ((drawable_t){.data = {.ptr = t}, .dtype = t})
/// Creates a text drawable.
#define DRAWABLE_TEXT(w) DRAWABLE(w, D_TEXT)
/// Creates a rect drawable.
#define DRAWABLE_RECT(w) DRAWABLE(w, D_RECT)
/// Creates a background drawable.
#define DRAWABLE_BG(w) DRAWABLE(w, D_BG)

void drawable_destroy(drawable_t *drawable);

/// Draws the values in @c map of type @ref drawable_t to the @c window.
void draw_from_map(my_hash_map_t const *map, sfRenderWindow *window);
/// Draws the values in @c elements to the @c window.
void draw_from_array(
    size_t count, drawable_t *elements[count], sfRenderWindow *window);
/// Draws the values in @c elements to the @c texture.
void draw_from_map_texture(my_hash_map_t *map, sfRenderTexture *texture);
/// Draws the values in @c map of type @ref drawable_t to the @c texture.
void draw_from_array_texture(
    size_t count, drawable_t *elements[count], sfRenderTexture *texture);

#endif
