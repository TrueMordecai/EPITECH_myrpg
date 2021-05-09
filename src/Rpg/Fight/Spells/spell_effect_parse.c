/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** spell_effect_parse
*/

#include <libmy/ascii.h>
#include <libmy/memory.h>
#include <libmy/parsing.h>
#include <libmy/printf.h>

#include "Rpg/Fight/spell.h"
#include "functions.h"

static int parse_value(
    size_t *offset, int name_len, char *line_beg, sfVector2i min_max)
{
    int nb;

    *offset = name_len;
    nb = get_number_pass(line_beg, offset);
    (*offset)--;
    CLAMP_ASSIGN(nb, min_max.x, min_max.y);
    return nb;
}

static void parse_line_elmts(spell_effect_t *spell, char *line_beg)
{
    size_t offset = 0;

    if (my_strncmp("EARTH=", line_beg, 6) == 0)
        spell->buff.elements[EARTH] =
            parse_value(&offset, 6, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("FIRE=", line_beg, 5) == 0)
        spell->buff.elements[FIRE] =
            parse_value(&offset, 5, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("WATER=", line_beg, 6) == 0)
        spell->buff.elements[WATER] =
            parse_value(&offset, 6, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("WIND=", line_beg, 5) == 0)
        spell->buff.elements[WIND] =
            parse_value(&offset, 5, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("EARTH_RES=", line_beg, 10) == 0)
        spell->buff.resistances[EARTH] =
            parse_value(&offset, 10, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("FIRE_RES=", line_beg, 9) == 0)
        spell->buff.resistances[FIRE] =
            parse_value(&offset, 9, line_beg, (sfVector2i){-100, 100});
}

static void parse_line_2(spell_effect_t *spell, char *line_beg)
{
    size_t offset = 0;

    if (my_strncmp("WATER_DMG=", line_beg, 10) == 0)
        spell->damages[WATER] =
            parse_value(&offset, 10, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("WIND_DMG=", line_beg, 9) == 0)
        spell->damages[WIND] =
            parse_value(&offset, 9, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("WATER_RES=", line_beg, 10) == 0)
        spell->buff.resistances[WATER] =
            parse_value(&offset, 10, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("WIND_RES=", line_beg, 9) == 0)
        spell->buff.resistances[WIND] =
            parse_value(&offset, 9, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("LIFETIME=", line_beg, 9) == 0)
        spell->lifetime =
            parse_value(&offset, 9, line_beg, (sfVector2i){1, 20});
    if (my_strncmp("MAX_CUMUL=", line_beg, 10) == 0)
        spell->max_cumul =
            parse_value(&offset, 10, line_beg, (sfVector2i){1, 5});
}

static void parse_line(spell_effect_t *spell, char *line_beg)
{
    size_t offset = 0;

    if (my_strncmp("EFFECT=", line_beg, 7) == 0)
        spell->type |= parse_effect_type(line_beg + 7);
    if (my_strncmp("LIFE=", line_beg, 5) == 0)
        spell->buff.life =
            parse_value(&offset, 5, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("PA_BOOST=", line_beg, 9) == 0)
        spell->buff.ap =
            parse_value(&offset, 9, line_beg, (sfVector2i){-10, 10});
    if (my_strncmp("PM=", line_beg, 3) == 0)
        spell->buff.pm =
            parse_value(&offset, 3, line_beg, (sfVector2i){-10, 10});
    if (my_strncmp("EARTH_DMG=", line_beg, 10) == 0)
        spell->damages[EARTH] =
            parse_value(&offset, 10, line_beg, (sfVector2i){-100, 100});
    if (my_strncmp("FIRE_DMG=", line_beg, 9) == 0)
        spell->damages[FIRE] =
            parse_value(&offset, 9, line_beg, (sfVector2i){-100, 100});
    parse_line_2(spell, line_beg);
    parse_line_elmts(spell, line_beg);
}

void spell_effect_parse(
    spell_effect_t *spell, char *file_content, size_t filesize)
{
    size_t offset = 0;
    int line_len;

    spell->lifetime = 1;
    spell->max_cumul = 2;
    spell->type = EFFECT_NONE;
    for (int i = 0; i < 4; i++)
        spell->damages[i] = 0;
    stats_init_blank(&spell->buff);
    while (offset < filesize) {
        line_len = my_strlen_to(file_content + offset, '\n');
        parse_line(spell, file_content + offset);
        offset += line_len + 1;
    }
}
