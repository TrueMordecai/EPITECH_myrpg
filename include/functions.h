/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** functions
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stddef.h>

#define ABS(a) (((a) >= 0) ? (a) : (-(a)))

#ifndef MAX
    #define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
    #define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef CLAMP
    /// Clamps a value between @c min and @c max.
    /// All of the parameters must be either of the same type or comparable
    /// with each other.
    ///
    /// @param v The value to clamp.
    /// @param min The minimum value, if @c a is lower than @c min, then @c min
    /// is returned.
    /// @param max The maximum value, if @c a is greater than @c max, then @c
    /// max is returned.
    ///
    /// @returns The clamped value.
    #define CLAMP(v, min, max) (MIN(MAX((min), (v)), (max)))
#endif

#define CLAMP_ASSIGN(v, min, max) (v = CLAMP(v, min, max))

/// Alias for CLAMP.
#define BTWN(a, min, max) CLAMP(a, min, max)

#define PI 3.14159265359

#define DEG_TO_RAD(x) ((x) * (PI / 180.f))

/// unused ?
#define MS_UPDATE 5

int is_in_bounds_i(
    sfVector2i pos, sfVector2i item_pos, sfVector2i item_size, int strict);
int is_in_bounds(sfVector2f pos, sfVector2f item_pos, sfVector2f item_size);
int is_in_rect(sfVector2f pos, sfFloatRect rect);

float get_rand(float min, float max);
int get_randi(int a, int b);
void center_mouse(sfRenderWindow *wind);

long get_number_adv(
    char const *str, size_t *offset, bool is_signed, bool only_num);
long get_number_pass(char const *str, size_t *offset);

#endif /* !FUNCTIONS_H */
