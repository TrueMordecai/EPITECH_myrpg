/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-andreas.leroux
** File description:
** quests_draw.c
*/

#include "Rpg/rpg.h"
#include <stddef.h>

void quests_draw(rpg_t *game)
{
    sfRenderWindow_drawSprite(game->wind, game->quests.dialogue.bg, NULL);
    sfRenderWindow_drawText(game->wind, game->quests.dialogue.text, NULL);
}