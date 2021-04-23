/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** playing_bubble_init
*/

#include "Rpg/Fight/timeline.h"

static void init_text(sfText *text, sfFont *font, char *str, sfVector2f pos)
{
    sfText_setCharacterSize(text, 18);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
}

void playing_bubble_init(playing_bubble_t *bubble, sfFont *font)
{
    bubble->circle = sfCircleShape_create();
    sfCircleShape_setFillColor(bubble->circle, sfRed);
    sfCircleShape_setOutlineColor(
        bubble->circle, sfColor_fromRGB(255, 131, 0));
    sfCircleShape_setOutlineThickness(bubble->circle, -3);
    sfCircleShape_setRadius(bubble->circle, CIRCLE_RADIUS);
    sfCircleShape_setPosition(bubble->circle,
        (sfVector2f){-CIRCLE_RADIUS * 1.6,
            -0.5 * (2 * CIRCLE_RADIUS - FRAME_WIDTH)}); //});
    bubble->text_pa = sfText_create();
    bubble->text_pm = sfText_create();
    init_text(bubble->text_pa, font, "6/6 PA",
        (sfVector2f){-CIRCLE_RADIUS * 1.2, CIRCLE_RADIUS * 0.1});
    init_text(bubble->text_pm, font, "6/6 PM",
        (sfVector2f){-CIRCLE_RADIUS * 1.2, CIRCLE_RADIUS * 0.9});
    sfText_setFillColor(bubble->text_pa, sfBlue);
    sfText_setFillColor(bubble->text_pm, sfGreen);
    bubble->last_entity = NULL;
}