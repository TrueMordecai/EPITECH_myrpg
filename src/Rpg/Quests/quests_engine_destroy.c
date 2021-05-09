/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** quests_engine_destroy
*/

#include <stdlib.h>

#include "Rpg/Quests/quests.h"

void quests_destroy(quest_list_t *quests)
{
    for (size_t i = 0; i < quests->nb_quests; i++)
        free(quests->quests[i].context);
    free(quests->quests);
    sfSprite_destroy(quests->dialogue.bg);
    sfText_destroy(quests->dialogue.text);
}