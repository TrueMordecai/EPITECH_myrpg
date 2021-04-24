/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spells_bar_draw
*/

#include "Rpg/Fight/spells_bar.h"

void spells_bar_draw(spells_bar_t *bar, sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getView(window);

    sfRenderWindow_setView(window, bar->view);
    sfRenderWindow_drawRectangleShape(window, bar->background, NULL);
    sfRenderWindow_drawRectangleShape(window, bar->move_bar, NULL);
    sfRenderWindow_drawRectangleShape(window, bar->life, NULL);
    sfRenderWindow_drawRectangleShape(window, bar->life_bg, NULL);
    sfRenderWindow_drawText(window, bar->text_pa, NULL);
    sfRenderWindow_drawText(window, bar->text_pm, NULL);
    for (int i = 0; i < bar->nb_frames; i++)
        sfRenderWindow_drawRectangleShape(window, bar->frames[i], NULL);
    sfRenderWindow_setView(window, view);
}