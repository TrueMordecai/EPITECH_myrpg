/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_draw
*/

#include "Rpg/InfoBox/infobox_spell.h"

static void draw_sub_struct(infobox_spell_base_t *info, sfRenderWindow *window)
{
    switch (info->spell->type) {
        case SPELL_ATTACK:
            infobox_spell_attack_draw((infobox_spell_attack_t *)info, window);
            break;
        case SPELL_HEAL:
            infobox_spell_heal_draw((infobox_spell_heal_t *)info, window);
            break;
        case SPELL_DEBUFF:
            infobox_spell_debuff_draw((infobox_spell_debuff_t *)info, window);
            break;
        case SPELL_EFFECT:
            infobox_spell_effect_draw((infobox_spell_effect_t *)info, window);
            break;
        default: break;
    }
}

void infobox_spell_draw(infobox_spell_base_t *info, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, info->name, NULL);
    sfRenderWindow_drawText(window, info->pa, NULL);
    sfRenderWindow_drawText(window, info->po, NULL);
    sfRenderWindow_drawText(window, info->turn_limit, NULL);
    sfRenderWindow_drawText(window, info->area, NULL);
    sfRenderWindow_drawText(window, info->type, NULL);
    draw_sub_struct(info, window);
}
