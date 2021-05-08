/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** quests_validate
*/

#include "Rpg/Quests/quests.h"
#include "Rpg/rpg.h"

quest_t *quests_get_current(quest_list_t *list)
{
    if (list->current_quest >= list->nb_quests)
        return NULL;
    return &list->quests[list->current_quest];
}

int quests_validate(quest_list_t *quest_list)
{
    if (quest_list->current_quest >= quest_list->nb_quests) {
        my_printf("No quest to validate\n");
        return 2;
    }
    quest_list->current_quest++;
    stats_gain_xp(quest_list->rpg->player->entity->stats, XP_TO_LEVEL_UP);
    if (quest_list->current_quest >= quest_list->nb_quests) {
        my_printf("Validate all quests\n");
        return 1;
    }
    my_printf("Next quest %#s\n",
        quest_list->quests[quest_list->current_quest].context);
    sfText_setString(quest_list->dialogue.text, \
        quest_list->quests[quest_list->current_quest].context);
    return 0;
}