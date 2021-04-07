/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** main
*/

#include <time.h>
#include "GameEngine/game_head.h"

static void show_usage(void)
{
    my_putstr("My World :\n\n  Description :\n");
    my_putstr("    In this game you can edit a 3D world");
    my_putstr("\n\n  Settings :\n");
    my_putstr(
        "    - Music / Sound volume : grab the snowflake to adjust the ");
    my_putstr(
        "volumes\n    - Window Size : change the width by clicking on i");
    my_putstr(
        "t and writing the size wanted\n    - Framerate : click in the ");
    my_putstr(
        "box and write the framerate wanted\n\n    All settings are val");
    my_putstr(
        "idated when clicking in the top right validate button \n    ex");
    my_putstr("cept for the size for which you must restart the game.\n\n");
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {0, 0, 32};
    game_data_t *data;

    srand((unsigned int)(((size_t)&mode)));
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0) {
        show_usage();
        return 0;
    }
    data = game_create(&mode, "My RPG");
    if (data == NULL)
        return 84;
    sfRenderWindow_setPosition(data->window, (sfVector2i){0, 0});
    run(data);
    game_destroy(data);
    return 0;
}
