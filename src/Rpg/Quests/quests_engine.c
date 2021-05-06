/*
** EPITECH PROJECT, 2021
** MyRPG - Quests
** File description:
** quests.c
*/

#include <libmy/parsing.h>

#include "Rpg/Quests/quests.h"

void free_all(quest_list_t *quests_data)
{
    int i = 0;

    for (; quests_data->list[i] != NULL; i++) {
        free(quests_data->list[i]);
    }
    free(quests_data->list[i]);
    free(quests_data->list);
}

void setup_quest_by_id(quest_list_t *quests_data)
{
    int nb_quest = 0;

    for (; quests_data->list[nb_quest] != NULL; nb_quest++)
        ;
    quests_data->quests = malloc(sizeof(quest_t) * nb_quest);
    for (int i = 0; quests_data->list[i] != NULL; i++) {
        quests_data->quests[i].quest_type = my_getnbr(quests_data->list[i]);
        parse_quest_info(quests_data, i);
    }
    quests_data->nb_quests = nb_quest;
}

int quests_init(quest_list_t *quests_data, char *filepath)
{
    quests_data->filepath = filepath;
    if (setup_data(quests_data) == -1)
        return (-1);
    setup_quest_by_id(quests_data);
    free_all(quests_data);
    quests_data->current_quest = 0;
    return 0;
}
