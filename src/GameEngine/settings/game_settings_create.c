/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game engine - settings init
*/

#include <fcntl.h>
#include "GameEngine/game_head.h"
#include "My/my_display.h"
#include "My/my_convert.h"
#include "functions.h"

static FILE *open_settings(void);

static FILE *create_settings(void)
{
    FILE *settings_file = fopen("./datas/settings.cfg", "w");

    if (settings_file == NULL){
        my_putstr_err("Can't create settings file\n");
        return NULL;
    }
    if (1 != fwrite("1280x720\n60\n100\n100\n", 21, 1, settings_file)){
        my_putstr_err("Can't write in settings file\n");
        fclose(settings_file);
        return NULL;
    }
    fclose(settings_file);
    return open_settings();
}

static FILE *open_settings(void)
{
    FILE *settings_file = fopen("./datas/settings.cfg", "r");

    if (settings_file == NULL)
        settings_file = create_settings();
    return settings_file;
}

static int try_read(size_t *len, FILE **file, char *buffer)
{
    *len = fread(buffer, 1, 1024, *file);
    if (*len <= 0){
        fclose(*file);
        *file = create_settings();
        if (file != NULL)
            *len = fread(buffer, 1, 1024, *file);
    }
    if (*len <= 0){
        my_putstr_err("Error reading config file\n");
        fclose(*file);
    }
    return (*len > 0);
}

void verif_settings(game_settings_t *settings)
{
    settings->wind_size.x = \
    BTWN(settings->wind_size.x, 500, sfVideoMode_getDesktopMode().width);
    settings->wind_size.y = \
    BTWN(settings->wind_size.y, 281, sfVideoMode_getDesktopMode().height);
    settings->limit_framerate = BTWN(settings->limit_framerate, 20, 300);
    settings->sound_volume = BTWN(settings->sound_volume, 0, 100);
    settings->music_volume = BTWN(settings->music_volume, 0, 100);
    if (ABS(settings->wind_size.x / settings->wind_size.y - 16/9.f) > 0.05)
        settings->wind_size.y = 1080.f * (settings->wind_size.x / 1920.f);
    settings->scale = settings->wind_size.x / 1920.f;
}

game_settings_t *game_settings_create(void)
{
    game_settings_t *settings;
    FILE *file = open_settings();
    char buffer[1025] = {0};
    size_t len;
    size_t i = 0;

    if (file == NULL || try_read(&len, &file, buffer) != 1)
        return NULL;
    settings = malloc(sizeof(game_settings_t));
    settings->wind_size.x = my_get_number_pass(buffer, &i);
    settings->wind_size.y = my_get_number_pass(buffer, &i);
    settings->limit_framerate = my_get_number_pass(buffer, &i);
    settings->music_volume = my_get_number_pass(buffer, &i);
    settings->sound_volume = my_get_number_pass(buffer, &i);
    verif_settings(settings);
    return settings;
}
