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

typedef struct game_data_t {
    struct state_t **states;
    struct sfRenderWindow *window;
    size_t *datas;
    struct asset_manager_t *assets;
    struct audio_manager_t *audio;
    struct game_settings_t *settings;
} game_data_t;

game_data_t *init_game(sfVideoMode *mode, char const *name);
void run(game_data_t *data);
void destroy_game(game_data_t *data);

#endif