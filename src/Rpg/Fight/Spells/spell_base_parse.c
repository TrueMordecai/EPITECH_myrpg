/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** spell_parse
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

static void parse_line2(spell_base_t *spell, char *line_beg)
{
    size_t offset = 0;

    if (my_strncmp("TURN_LIMIT=", line_beg, 11) == 0)
        spell->turn_limit =
            parse_value(&offset, 11, line_beg, (sfVector2i){1, 6});
    if (my_strncmp("TEXTURE_ID=", line_beg, 11) == 0)
        spell->texture_id =
            parse_value(&offset, 11, line_beg, (sfVector2i){0, 8});
}

static int parse_line(spell_base_t *spell, char *line_beg)
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
        spell->po = parse_value(&offset, 3, line_beg, (sfVector2i){0, 30});
    if (my_strncmp("AP=", line_beg, 3) == 0)
        spell->ap = parse_value(&offset, 3, line_beg, (sfVector2i){1, 6});
    if (my_strncmp("AREA=", line_beg, 5) == 0)
        spell->area = parse_value(&offset, 5, line_beg, (sfVector2i){0, 10});
    parse_line2(spell, line_beg);
    if (offset == 0 || line_beg[offset] != '\n')
        return 1;
    return 0;
}

static void parse_types(spell_base_t *spell, char *parse_beg, size_t filesize)
{
    switch (spell->type) {
        case SPELL_ATTACK:
            spell_attack_parse((spell_attack_t *)spell, parse_beg, filesize);
            break;
        case SPELL_HEAL:
            spell_heal_parse((spell_heal_t *)spell, parse_beg, filesize);
            break;
        case SPELL_DEBUFF:
            spell_debuff_parse((spell_debuff_t *)spell, parse_beg, filesize);
            break;
        case SPELL_EFFECT:
            spell_effect_parse((spell_effect_t *)spell, parse_beg, filesize);
            break;
        default: break;
    }
}

void spell_base_parse(spell_base_t *spell, char *file_content, size_t filesize)
{
    size_t offset = 0;
    int line_len;

    spell->name = NULL;
    spell->ap = 1;
    spell->po = 0;
    spell->texture_id = 0;
    spell->area = 1;
    spell->turn_limit = 3;
    spell->cast_left = 3;
    while (offset < filesize) {
        line_len = my_strlen_to(file_content + offset, '\n');
        parse_line(spell, file_content + offset);
        offset += line_len + 1;
    }
    parse_types(spell, file_content, filesize);
}
