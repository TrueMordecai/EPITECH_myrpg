/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** spell_attack_parse
*/

#include <libmy/ascii.h>
#include <libmy/memory.h>
#include <libmy/parsing.h>
#include <libmy/printf.h>

#include "Rpg/Fight/spell.h"
#include "functions.h"

static int parse_value(size_t *offset, int name_len, char *line_beg)
{
    int nb;

    *offset = name_len;
    nb = get_number_pass(line_beg, offset);
    (*offset)--;
    CLAMP_ASSIGN(nb, -100, 100);
    return nb;
}

static int parse_line(spell_attack_t *spell, char *line_beg)
{
    size_t offset = 0;

    if (my_strncmp("EARTH=", line_beg, 6) == 0)
        spell->damages[EARTH] = parse_value(&offset, 6, line_beg);
    if (my_strncmp("FIRE=", line_beg, 5) == 0)
        spell->damages[FIRE] = parse_value(&offset, 5, line_beg);
    if (my_strncmp("WATER=", line_beg, 6) == 0)
        spell->damages[WATER] = parse_value(&offset, 6, line_beg);
    if (my_strncmp("WIND=", line_beg, 5) == 0)
        spell->damages[WIND] = parse_value(&offset, 5, line_beg);
    if (offset == 0 || line_beg[offset] != '\n')
        return 1;
    return 0;
}

void spell_attack_parse(
    spell_attack_t *spell, char *file_content, size_t filesize)
{
    size_t offset = 0;
    int line_len;

    for (int i = 0; i < 4; i++)
        spell->damages[i] = 0;
    while (offset < filesize) {
        line_len = my_strlen_to(file_content + offset, '\n');
        parse_line(spell, file_content + offset);
        offset += line_len + 1;
    }
}
