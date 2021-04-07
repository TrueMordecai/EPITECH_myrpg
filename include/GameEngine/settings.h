/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game engine - settings
*/

#ifndef GE_SETTINGS_H
#define GE_SETTINGS_H

#include <SFML/Graphics.h>

#include "types.h"

#define SCL(state) (state->game_data->settings->scale)
#define SL(rpg)    SCL((rpg)->state)

struct game_settings {
    sfVector2u wind_size;
    unsigned int limit_framerate;
    float music_volume;
    float sound_volume;
    float scale;
};

game_settings_t *game_settings_create(void);
void game_settings_destroy(game_settings_t *settings);

/// FIXME: FRENGLISH strikes again!
void verif_settings(game_settings_t *settings);
int game_settings_save(game_settings_t *settings);

#endif /* !GE_SETTINGS_H */
