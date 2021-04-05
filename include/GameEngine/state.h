/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Game State
*/

#ifndef GE_STATE_H
#define GE_STATE_H

#include <libmy/collections/vec.h>

enum STATE_ID { NONE, MENU_STATE, SETTINGS_STATE, GAME_STATE };

struct game_data_t;
struct drawable_list_t;

typedef struct state_t {
    int (*init)(struct state_t *);
    int (*pause)(struct state_t *, int);
    int (*resume)(struct state_t *, int);
    int (*handle_input)(struct state_t *);
    int (*update)(struct state_t *, float);
    int (*draw)(struct state_t *, float);
    int (*destroy)(struct state_t *, int);
    struct game_data_t *game_data;
    /// A vector of @ref drawable element maps.
    /// Each map has the following types:
    /// - Key  : unsigned char
    /// - Value: draw_elmt_t *
    my_vec_t draw_layers;
    int state_id;
    size_t *state_datas;
} state_t;

typedef int (*state_setfcts_t)(game_data_t *, state_t *, size_t);

void end_state(game_data_t *data, int from);
void add_state(game_data_t *data,
    int (*state_setfcts)(game_data_t *, state_t *, size_t), int replace,
    size_t datas);

#endif
