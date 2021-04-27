/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spell_create_from_file
*/

#include <libmy/ascii.h>
#include <libmy/io/iostream.h>
#include <stdlib.h>

#include "Rpg/Fight/spell.h"
#include "functions.h"

enum spell_type_e get_spell_type(char *path, char *file_content)
{
    int line_len = my_strlen_to(file_content, '\n');

    if (!file_content)
        return SPELL_NONE;
    if (my_strncmp("TYPE=", file_content, 5)) {
        my_fprintf(MY_STDERR, "No spell type found in %#s\n", path);
        return SPELL_NONE;
    }
    if (my_strncmp("ATTACK\n", file_content + 5, 7) == 0)
        return SPELL_ATTACK;
    if (my_strncmp("HEAL\n", file_content + 5, 5) == 0)
        return SPELL_HEAL;
    if (my_strncmp("EFFECT\n", file_content + 5, 7) == 0)
        return SPELL_EFFECT;
    if (my_strncmp("DEBUFF\n", file_content + 5, 7) == 0)
        return SPELL_DEBUFF;
    my_fprintf(MY_STDERR, "Unknow spell type %#.*s in %#s\n", line_len - 5,
        file_content + 5, path);
    return SPELL_NONE;
}

spell_base_t *spell_create_from_type(enum spell_type_e type)
{
    spell_base_t *spell = NULL;

    switch (type) {
        case SPELL_ATTACK: spell = malloc(sizeof(spell_attack_t)); break;
        case SPELL_HEAL: spell = malloc(sizeof(spell_heal_t)); break;
        case SPELL_EFFECT: spell = malloc(sizeof(spell_effect_t)); break;
        case SPELL_DEBUFF: spell = malloc(sizeof(spell_debuff_t)); break;
        default: break;
    }
    return spell;
}

spell_base_t *spell_create_from_file(char *file)
{
    size_t file_size;
    char *file_content = read_file(file, &file_size);
    enum spell_type_e spell_type = get_spell_type(file, file_content);
    spell_base_t *spell = NULL;

    if (file_content == NULL || spell_type == SPELL_NONE) {
        if (file_content)
            free(file_content);
        return NULL;
    }
    spell = spell_create_from_type(spell_type);
    spell->type = spell_type;
    spell->area = 1;
    assert(spell != NULL);
    spell_base_parse(spell,
        file_content + my_strlen_to(file_content, '\n') + 1,
        file_size - (my_strlen_to(file_content, '\n') + 1));
    free(file_content);
    return spell;
}