/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** functions
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>
#include <SFML/Graphics.h>

struct state_t;

#define ABS(a) (((a) >= 0) ? (a) : (-(a)))
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif
#define BTWN(a, min, max) (MIN(MAX((min), (a)), (max)))
#define PI 3.14159265359
#define DEG_TO_RAD(x) ((x) * (PI / 180.f))

#define MS_UPDATE 5

int my_map_strcmp(char *s1, size_t s2);
int my_map_intcmp(char *s1, size_t s2);
int my_map_charcmp(char *s1, size_t s2);

int is_in_bounds_i(sfVector2i pos, sfVector2i item_pos, \
sfVector2i item_size, int strict);
int is_in_bounds(sfVector2f pos, sfVector2f item_pos, sfVector2f item_size);
int is_in_rect(sfVector2f pos, sfFloatRect rect);

float get_rand(float min, float max);
int get_randi(int a, int b);
void center_mouse(sfRenderWindow *wind);

#endif /* !FUNCTIONS_H */
