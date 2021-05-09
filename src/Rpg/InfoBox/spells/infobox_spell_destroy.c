/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Destroys a spell infobox
*/

#include "Rpg/InfoBox/infobox_spell.h"

static void destroy_substruct(infobox_spell_base_t *info)
{
    switch (info->spell->type) {
        case SPELL_ATTACK:
            infobox_spell_attack_destroy((infobox_spell_attack_t *)info);
            break;
        case SPELL_HEAL:
            infobox_spell_heal_destroy((infobox_spell_heal_t *)info);
            break;
        case SPELL_DEBUFF:
            infobox_spell_debuff_destroy((infobox_spell_debuff_t *)info);
            break;
        case SPELL_EFFECT:
            infobox_spell_effect_destroy((infobox_spell_effect_t *)info);
            break;
        default: break;
    }
}

void infobox_spell_destroy(infobox_spell_base_t *info)
{
    destroy_substruct(info);
    sfText_destroy(info->name);
    sfText_destroy(info->ap);
    sfText_destroy(info->op);
    sfText_destroy(info->area);
    sfText_destroy(info->type);
    sfText_destroy(info->turn_limit);
}
