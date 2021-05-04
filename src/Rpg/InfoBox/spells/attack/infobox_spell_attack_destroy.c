/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_spell_destroy
*/

#include <stdlib.h>

#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_attack_destroy_lines(infobox_spell_attack_t *info)
{
    for (int i = 0; i < info->nb_lines; i++) {
        sfText_destroy(info->elements[0][i]);
        sfText_destroy(info->elements[1][i]);
    }
    free(info->elements[0]);
    free(info->elements[1]);
}

void infobox_spell_attack_destroy(infobox_spell_attack_t *info)
{
    sfText_destroy(info->damages);
    infobox_spell_attack_destroy_lines(info);
}