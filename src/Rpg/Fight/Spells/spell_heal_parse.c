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
    CLAMP_ASSIGN(nb, 1, 100);
    return nb;
}

static int parse_line(spell_heal_t *spell, char *line_beg)
{
    size_t offset = 0;

    if (my_strncmp("HEAL=", line_beg, 5) == 0)
        spell->heal = parse_value(&offset, 5, line_beg);
    if (offset == 0 || line_beg[offset] != '\n')
        return 1;
    return 0;
}

void spell_heal_parse(spell_heal_t *spell, char *file_content, size_t filesize)
{
    size_t offset = 0;
    int line_len;

    spell->heal = 0;
    while (offset < filesize) {
        line_len = my_strlen_to(file_content + offset, '\n');
        parse_line(spell, file_content + offset);
        offset += line_len + 1;
    }
}
