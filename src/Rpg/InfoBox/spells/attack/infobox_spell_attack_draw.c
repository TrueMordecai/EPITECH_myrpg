/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_spell_draw
*/

#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_attack_draw(
    infobox_spell_attack_t *info, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, info->damages, NULL);
    for (int i = 0; i < info->nb_lines; i++) {
        sfRenderWindow_drawText(window, info->elements[0][i], NULL);
        sfRenderWindow_drawText(window, info->elements[1][i], NULL);
    }
}