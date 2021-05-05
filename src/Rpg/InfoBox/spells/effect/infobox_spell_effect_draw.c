/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_draw
*/

#include "Rpg/InfoBox/infobox_spell.h"

void infobox_spell_effect_draw(
    infobox_spell_effect_t *info, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, info->lifetime, NULL);
    sfRenderWindow_drawText(window, info->max_cumul, NULL);
    if (info->boosts.length)
        sfRenderWindow_drawText(window, info->boost, NULL);
    if (info->damages.length)
        sfRenderWindow_drawText(window, info->damage, NULL);
    for (size_t i = 0; i < info->boosts.length; i++)
        sfRenderWindow_drawText(
            window, MY_VEC_GET_ELEM(sfText *, &info->boosts, i), NULL);
    for (size_t i = 0; i < info->damages.length; i++)
        sfRenderWindow_drawText(
            window, MY_VEC_GET_ELEM(sfText *, &info->damages, i), NULL);
}
