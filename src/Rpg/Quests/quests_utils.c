/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** quests_validate
*/

#include <libmy/ascii.h>

#include "Rpg/Quests/quests.h"
#include "Rpg/rpg.h"

quest_t *quests_get_current(quest_list_t *list)
{
    if (list->current_quest >= list->nb_quests)
        return NULL;
    return &list->quests[list->current_quest];
}

static void set_quest_text(sfText *text, char *str, float scl)
{
    size_t len = my_strlen(str);
    int last_space = 0;
    sfVector2f pos;

    sfText_setString(text, str);
    for (size_t i = 0; i < len; i++) {
        if (str[i] == ' ')
            last_space = i;
        if (str[i] == '\n')
            continue;
        pos = sfText_findCharacterPos(text, i);
        if (pos.x > 1575 * scl) {
            str[last_space] = '\n';
            set_quest_text(text, str, scl);
            return;
        }
    }
}

int quests_validate(quest_list_t *quest_list)
{
    if (quest_list->current_quest >= quest_list->nb_quests) {
        my_printf("No quest to validate\n");
        return 2;
    }
    quest_list->current_quest++;
    stats_gain_xp(quest_list->rpg->player->entity->stats, XP_TO_LEVEL_UP);
    play_sound(&quest_list->rpg->state->game_data->audio, "quest_success");
    if (quest_list->current_quest >= quest_list->nb_quests) {
        my_printf("Validate all quests\n");
        return 1;
    }
    my_printf("Next quest %#s\n",
        quest_list->quests[quest_list->current_quest].context);
    set_quest_text(quest_list->dialogue.text,
        quest_list->quests[quest_list->current_quest].context,
        SL(quest_list->rpg));
    return 0;
}