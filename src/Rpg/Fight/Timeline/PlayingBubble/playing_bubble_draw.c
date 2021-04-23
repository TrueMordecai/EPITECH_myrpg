/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** playing_bubble_draw
*/

#include "Rpg/Fight/timeline.h"

void playing_bubble_draw(playing_bubble_t *bubble, sfRenderWindow *window)
{
    sfRenderWindow_drawCircleShape(window, bubble->circle, NULL);
    sfRenderWindow_drawText(window, bubble->text_pa, NULL);
    sfRenderWindow_drawText(window, bubble->text_pm, NULL);
}