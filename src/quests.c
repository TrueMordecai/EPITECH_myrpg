/*
** EPITECH PROJECT, 2020
** Quêtes
** File description:
** quests.c
*/

#include "quests.h"

void free_all(t_data *quests_data)
{
    int i = 0;

    for (; quests_data->quests_list[i] != NULL; i++) {
        free(quests_data->quests_list[i]);
    }
    free(quests_data->quests_list[i]);
    free(quests_data->quests_list);
}

void setup_quest_by_id(t_data *quests_data)
{
    int nb_quest = 0;

    for (; quests_data->quests_list[nb_quest] != NULL; nb_quest++);
    quests_data->quest = malloc(sizeof(t_quest) * nb_quest);
    for (int i = 0; quests_data->quests_list[i] != NULL; i++) {
        quests_data->quest[i].quest_type = \
        my_getnbr(quests_data->quests_list[i]);
        parse_quest_info(quests_data, i);
    }
}

quest_t *quests(char *filepath, int quest_id)
{
    t_data quests_data;

    quests_data.filepath = filepath;
    if (setup_data(&quests_data) == -1)
        return (-1);
    setup_quest_by_id(&quests_data);
    free_all(&quests_data);
    return (quests_data.quest);
}