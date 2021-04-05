/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game Engine - save settings
*/

#include <fcntl.h>
#include "GameEngine/game_head.h"
#include "My/my_display.h"
#include "My/my_convert.h"
#include "My/my_strings.h"
#include "functions.h"

static int write_value(int value, FILE *file, char end_char)
{
    int size_str = my_number_len(value) + (end_char != 0);
    char *str = malloc(sizeof(char) * (size_str + 1));
    char *p = str;
    char *istr = my_itostr(value);
    int return_code;

    my_strnset(str, 0, size_str + 1);
    p = my_strcat(p, istr);
    free(istr);
    if (end_char != 0)
        str[size_str - 1] = end_char;
    return_code = fwrite(str, size_str, 1, file);
    free(str);
    return return_code;
}

static int write_settings(game_settings_t *settings, FILE *file)
{
    if (write_value(settings->wind_size.x, file, 'x') != 1 || \
    write_value(settings->wind_size.y, file, '\n') != 1 || \
    write_value(settings->limit_framerate, file, '\n') != 1 || \
    write_value(settings->music_volume, file, '\n') != 1 || \
    write_value(settings->sound_volume, file, '\n') != 1) {
        return -1;
    }
    return 0;
}

int game_settings_save(game_settings_t *settings)
{
    FILE *settings_file = fopen("./datas/settings.cfg", "w");

    verif_settings(settings);
    if (settings_file == NULL){
        my_putstr_err("Can't create settings file\n");
        return 0;
    }
    if (write_settings(settings, settings_file) == -1){
        my_putstr_err("Error occured while saving settings\n");
        fclose(settings_file);
        return 0;
    }
    fclose(settings_file);
    return 1;
}