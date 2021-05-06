/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** main
*/

#include <sys/types.h>

#include <dirent.h>
#include <libmy/ascii.h>
#include <libmy/io/iostream.h>
#include <libmy/printf.h>
#include <stdlib.h>
#include <time.h>

#include "Rpg/Fight/spell.h"
#include "GameEngine/game_head.h"

sfTexture *get_null_texture(void);
sfFont *get_null_font(void);

static const size_t IO_BUF_SIZE = 512;

static void show_usage(void)
{
    my_puts("My World :\n\n  Description :\n");
    my_puts("    In this game you can edit a 3D world");
    my_puts("\n\n  Settings :\n");
    my_puts("    - Music / Sound volume : grab the snowflake to adjust the ");
    my_puts("volumes\n    - Window Size : change the width by clicking on i");
    my_puts("t and writing the size wanted\n    - Framerate : click in the ");
    my_puts("box and write the framerate wanted\n\n    All settings are val");
    my_puts("idated when clicking in the top right validate button \n    ex");
    my_puts("cept for the size for which you must restart the game.\n\n");
    my_fflush(MY_STDOUT);
}

int my_rpg(int argc, char *argv[])
{
    sfVideoMode mode = {0, 0, 32};
    game_data_t *data;
    DIR *assets = opendir("assets");

    if (!assets) {
        my_fprintf(MY_STDERR, "%s: missing assets folder\n", argv[0]);
        return 84;
    } else
        closedir(assets);
    srand((unsigned int)(((size_t)&mode)));
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0) {
        show_usage();
        return 0;
    }
    data = game_data_create(&mode, "My RPG");
    if (data == NULL)
        return 84;
    sfRenderWindow_setPosition(data->window, (sfVector2i){0, 0});
    run(data);
    game_data_destroy(data);
    return 0;
}

int main(int argc, char *argv[])
{
    int ret;

    if (my_init_stderr(malloc(IO_BUF_SIZE), IO_BUF_SIZE, &free))
        return 84;
    if (my_init_stdout(malloc(IO_BUF_SIZE), IO_BUF_SIZE, &free)) {
        my_free_stderr();
        return 84;
    }
    ret = my_rpg(argc, argv);
    my_free_stderr();
    my_free_stdout();
    sfFont_destroy(get_null_font());
    sfTexture_destroy(get_null_texture());
    return ret;
}
