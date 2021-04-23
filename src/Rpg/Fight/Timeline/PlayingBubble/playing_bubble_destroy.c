/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** playing_bubble_destroy
*/

#include "Rpg/Fight/timeline.h"

void playing_bubble_destroy(playing_bubble_t *bubble)
{
    sfCircleShape_destroy(bubble->circle);
    sfText_destroy(bubble->text_pa);
    sfText_destroy(bubble->text_pm);
}