/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** spells_bar_destroy
*/

#include <stdlib.h>
#include "Rpg/Fight/spells_bar.h"

void spells_bar_destroy(spells_bar_t *bar)
{
    for (int i = 0; i < bar->nb_frames; i++)
        sfRectangleShape_destroy(bar->frames[i]);
    free(bar->frames);
    sfView_destroy(bar->view);
    sfRectangleShape_destroy(bar->background);
    sfRectangleShape_destroy(bar->move_bar);
    sfRectangleShape_destroy(bar->life_bg);
    sfRectangleShape_destroy(bar->life);
    sfText_destroy(bar->text_pa);
    sfText_destroy(bar->text_pm);
}
