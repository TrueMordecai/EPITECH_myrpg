/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_draw
*/

#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_debuff_draw(
    infobox_spell_debuff_t *info, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, info->type, NULL);
    sfRenderWindow_drawText(window, info->turn_removed, NULL);
}
