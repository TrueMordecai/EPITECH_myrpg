/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_init
*/

#include "GameEngine/settings.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_heal_init(infobox_spell_heal_t *info, spell_heal_t *spell)
{
    infobox_create_text((infobox_base_t *)info, &info->heal, sfWhite, 25);
    infobox_spell_heal_set_spell(info, spell);
}
