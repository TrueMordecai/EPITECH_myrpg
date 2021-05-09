/*
** EPITECH PROJECT, 2020
** MyRPG
** File description:
** Draws quest dialogue
*/

#include <stddef.h>
#include "Rpg/rpg.h"

void quests_draw(rpg_t *game)
{
    sfRenderWindow_drawSprite(game->wind, game->quests.dialogue.bg, NULL);
    sfRenderWindow_drawText(game->wind, game->quests.dialogue.text, NULL);
}
