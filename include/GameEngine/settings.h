/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game engine - settings
*/

#ifndef GE_SETTINGS_H
#define GE_SETTINGS_H

#include <SFML/Graphics.h>

#define SCL(state) (state->game_data->settings->scale)
#define SL(rpg)    SCL((rpg)->state)

typedef struct game_settings_s {
    sfVector2u wind_size;
    unsigned int limit_framerate;
    float music_volume;
    float sound_volume;
    float scale;
} game_settings_t;

void verif_settings(game_settings_t *settings);
game_settings_t *game_settings_init(void);
int game_settings_save(game_settings_t *settings);

#endif /* !GE_SETTINGS_H */
