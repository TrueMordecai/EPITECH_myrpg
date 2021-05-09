/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Initializes a spell infobox
*/

#include "GameEngine/settings.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_spell.h"

static void init_sub_struct(infobox_spell_base_t *info, spell_base_t *spell)
{
    switch (info->spell->type) {
        case SPELL_ATTACK:
            infobox_spell_attack_init(
                (infobox_spell_attack_t *)info, (spell_attack_t *)spell);
            break;
        case SPELL_HEAL:
            infobox_spell_heal_init(
                (infobox_spell_heal_t *)info, (spell_heal_t *)spell);
            break;
        case SPELL_DEBUFF:
            infobox_spell_debuff_init(
                (infobox_spell_debuff_t *)info, (spell_debuff_t *)spell);
            break;
        case SPELL_EFFECT:
            infobox_spell_effect_init(
                (infobox_spell_effect_t *)info, (spell_effect_t *)spell);
            break;
        default: break;
    }
}

void infobox_spell_init(infobox_spell_base_t *info, spell_base_t *spell)
{
    info->spell = spell;
    sfRectangleShape_setOutlineThickness(info->base.icon, 0);
    sfRectangleShape_setTexture(info->base.icon,
        get_texture(&info->base.rpg->state->game_data->assets, "spells"), 1);
    infobox_create_text(&info->base, &info->name, sfWhite, 35);
    infobox_create_text(&info->base, &info->ap, sfWhite, 25);
    infobox_create_text(&info->base, &info->op, sfWhite, 25);
    infobox_create_text(&info->base, &info->turn_limit, sfWhite, 25);
    infobox_create_text(&info->base, &info->type, sfWhite, 25);
    infobox_create_text(&info->base, &info->area, sfWhite, 25);
    init_sub_struct(info, spell);
    infobox_spell_set_spell(&info, spell);
}
