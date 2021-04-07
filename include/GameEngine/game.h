/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Game struct
*/

#ifndef GE_GAME_H
#define GE_GAME_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <libmy/collections/vec.h>

#include "types.h"

typedef struct game_data_t {
    /// A vector of element type 'state_t' (note the lack of a '*')
    my_vec_t states;
    /// Array of state data, same size as @ref states.
    size_t *datas;
    struct sfRenderWindow *window;
    struct asset_manager_t *assets;
    struct audio_manager_t *audio;
    struct game_settings_t *settings;
} game_data_t;

game_data_t *init_game(sfVideoMode *mode, char const *name);
void run(game_data_t *data);
void destroy_game(game_data_t *data);

#endif // !defined(GE_GAME_H)
