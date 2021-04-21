/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spell_parse
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
    return nb;
}

int parse_line(spell_base_t *spell, char *line_beg, int line_len)
{
    size_t offset = 0;
    int diff;

    if (my_strncmp("NAME=", line_beg, 5) == 0) {
        diff = 5 + (line_beg[5] == '"');
        spell->name = my_strndup(line_beg + diff,
            my_strlen_to(line_beg + diff, ((diff == 6) ? '"' : '\n')));
        return 0;
    }
    if (my_strncmp("PO=", line_beg, 3) == 0)
        spell->po = parse_value(&offset, 3, line_beg);
    if (my_strncmp("PA=", line_beg, 3) == 0)
        spell->pa = parse_value(&offset, 3, line_beg);
    if (my_strncmp("AREA=", line_beg, 5) == 0)
        spell->area = parse_value(&offset, 5, line_beg);
    if (offset == 0 || line_beg[offset] != '\n')
        return 1;
    return 0;
}

void spell_base_parse(spell_base_t *spell, char *file_content)
{
    size_t offset = 0;
    int line_len;

    spell->name = NULL;
    spell->pa = 1;
    spell->po = 0;
    spell->area = 0;
    while (file_content[offset]) {
        line_len = my_strlen_to(file_content + offset, '\n');
        parse_line(spell, file_content + offset, line_len);
        offset += line_len + 1;
    }
    my_printf("Name = %#s\n   Pa = %d\n   Po = %d\n   Area = %d\n",
        spell->name, spell->pa, spell->po, spell->area);
}