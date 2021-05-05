/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_destroy
*/

#include <stdlib.h>

#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_debuff_destroy(infobox_spell_debuff_t *info)
{
    sfText_destroy(info->type);
    sfText_destroy(info->turn_removed);
}
