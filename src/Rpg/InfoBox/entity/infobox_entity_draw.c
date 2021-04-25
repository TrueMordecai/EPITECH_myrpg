/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_entity_draw
*/

#include "Rpg/InfoBox/infobox_entity.h"

void infobox_entity_draw(infobox_entity_t *info, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, info->name, NULL);
    sfRenderWindow_drawText(window, info->level, NULL);
    sfRenderWindow_drawText(window, info->life, NULL);
    sfRenderWindow_drawText(window, info->pa, NULL);
    sfRenderWindow_drawText(window, info->pm, NULL);
    sfRenderWindow_drawText(window, info->damage, NULL);
    sfRenderWindow_drawText(window, info->resistance, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(window, info->elements[0][i], NULL);
        sfRenderWindow_drawText(window, info->elements[1][i], NULL);
        sfRenderWindow_drawText(window, info->elements[2][i], NULL);
    }
    if (info->effect_names.length == 0)
        return;
    sfRenderWindow_drawText(window, info->effects, NULL);
    for (size_t i = 0; i < info->effect_names.length; i++) {
        sfRenderWindow_drawText(
            window, MY_VEC_GET_ELEM(sfText *, &info->effect_names, i), NULL);
    }
}