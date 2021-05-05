/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_init
*/

#include "GameEngine/settings.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_effect_init(
    infobox_spell_effect_t *info, spell_effect_t *spell)
{
    my_vec_init(&info->boosts, sizeof(sfText *));
    my_vec_init(&info->damages, sizeof(sfText *));
    infobox_create_text((infobox_base_t *)info, &info->lifetime, sfWhite, 25);
    infobox_create_text((infobox_base_t *)info, &info->max_cumul, sfWhite, 25);
    infobox_create_text((infobox_base_t *)info, &info->boost, sfWhite, 30);
    infobox_create_text((infobox_base_t *)info, &info->damage, sfWhite, 30);
    infobox_spell_effect_set_spell(info, spell);
}
