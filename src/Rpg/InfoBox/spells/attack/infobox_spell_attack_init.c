/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_spell_init
*/

#include "GameEngine/settings.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_attack_init(
    infobox_spell_attack_t *info, spell_attack_t *spell)
{
    info->nb_lines = 0;
    info->elements[0] = NULL;
    info->elements[1] = NULL;
    infobox_create_text((infobox_base_t *)info, &info->damages, sfWhite, 30);
    infobox_spell_attack_set_spell(info, spell);
}