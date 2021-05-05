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

static int is_end_char_ok(char *line, size_t offset, int len_value)
{
    return (line[offset + len_value] == 0 || line[offset + len_value] == '+'
        || line[offset + len_value] == '\n');
}

enum effect_type_e parse_effect_type(char *line)
{
    size_t offset = 0;
    size_t len = my_strlen_to(line, '\n');
    int found = 1;
    enum effect_type_e type = EFFECT_NONE;

    while (offset < len && found) {
        found = 0;
        if (my_strncmp("BOOST", line + offset, 5) == 0
            && is_end_char_ok(line, offset, 5)) {
            found = 1;
            type |= EFFECT_BOOST;
            offset += 5 + (line[offset + 6] != 0);
        }
        if (my_strncmp("DAMAGE", line + offset, 6) == 0
            && is_end_char_ok(line, offset, 6)) {
            found = 1;
            type |= EFFECT_DAMAGE;
            offset += 6 + (line[offset + 7] != 0);
        }
    }
    return type;
}

void spell_debuff_parse(
    spell_debuff_t *spell, char *file_content, size_t filesize)
{
    size_t offset = 0;
    int line_len;

    spell->type = EFFECT_NONE;
    spell->turns = 0;
    while (offset < filesize) {
        line_len = my_strlen_to(file_content + offset, '\n');
        if (my_strncmp("DEBUFF=", file_content + offset, 7) == 0)
            spell->type |= parse_effect_type(file_content + offset + 7);
        if (my_strncmp("TURNS=", file_content + offset, 6) == 0)
            spell->turns = get_number_pass(file_content + offset + 6, NULL);
        offset += line_len + 1;
    }
}
