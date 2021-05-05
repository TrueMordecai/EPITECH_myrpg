/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_text
*/

#include <libmy/parsing/parsing.h>
#include <libmy/printf/printf.h>
#include <stdarg.h>

#include "GameEngine/settings.h"
#include "Rpg/InfoBox/infobox.h"
#include "Rpg/rpg.h"

void infobox_set_text_pos(sfText *text, sfVector3f pos)
{
    sfFloatRect bounds;

    sfText_setOrigin(text, (sfVector2f){0, 0});
    bounds = sfText_getLocalBounds(text);
    if (pos.z < 0)
        sfText_setPosition(text, (sfVector2f){(int)pos.x, (int)pos.y});
    if (pos.z == 0)
        sfText_setPosition(
            text, (sfVector2f){(int)(pos.x - bounds.width / 2.0), (int)pos.y});
    if (pos.z > 0)
        sfText_setPosition(
            text, (sfVector2f){(int)(pos.x - bounds.width), (int)pos.y});
}

void infobox_init_text(sfText *text, char const *format, sfVector3f pos, ...)
{
    char *str = NULL;
    va_list args;

    va_start(args, pos);
    my_vasprintf(&str, format, args);
    va_end(args);
    sfText_setString(text, str);
    infobox_set_text_pos(text, pos);
    free(str);
}

void infobox_create_text(
    infobox_base_t *base, sfText **text, sfColor color, int char_size)
{
    *text = sfText_create();
    sfText_setFont(*text, base->font);
    sfText_setCharacterSize(*text, char_size * SL(base->rpg));
    sfText_setFillColor(*text, color);
    sfText_setOrigin(*text, (sfVector2f){0, 0});
}
