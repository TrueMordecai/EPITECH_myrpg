/*
** EPITECH PROJECT, 2021
** Game Engine
** File description:
** Game struct
*/

#ifndef GE_GAME_H
#define GE_GAME_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <libmy/collections/vec.h>
#include <stdbool.h>

#include "types.h"

#include "asset_manager.h"
#include "audio_manager.h"

struct game_data {
    /// A vector of element type 'state_t *'
    my_vec_t states;
    sfRenderWindow *window;
    asset_manager_t assets;
    audio_manager_t audio;
    settings_t settings;
    particle_manager_t *particles;
};

void run(game_data_t *data);

game_data_t *game_data_create(sfVideoMode *mode, char const *name);
void game_data_destroy(game_data_t *data);

/// Allocates and initializes a state.
typedef state_t *(*state_create_t)(game_data_t *);

int game_data_push_state(
    game_data_t *data, state_create_t create_state, bool replace);
void game_data_pop_state(game_data_t *data, state_id_t from);

#endif // !defined(GE_GAME_H)
