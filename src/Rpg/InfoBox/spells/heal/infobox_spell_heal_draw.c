/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_draw
*/

#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_heal_draw(
    infobox_spell_heal_t *info, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, info->heal, NULL);
}
