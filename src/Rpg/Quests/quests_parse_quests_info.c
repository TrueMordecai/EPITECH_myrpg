/*
** EPITECH PROJECT, 2021
** MyRPG - Quests
** File description:
** parse_quests_info.c
*/

#include <libmy/ascii.h>
#include <libmy/parsing.h>
#include "Rpg/Quests/quests.h"

int setup_kill_monster(quest_list_t *quest_data, int index_quest)
{
    int i = 2;

    quest_data->quests[index_quest].state = 0;
    quest_data->quests[index_quest].quest_type = 1;
    quest_data->quests[index_quest].kill_monster.type_id =
        my_getnbr(&quest_data->list[index_quest][2]);
    for (; quest_data->list[index_quest][i] != ' '; i++)
        ;
    i++;
    quest_data->quests[index_quest].kill_monster.type_id =
        my_getnbr(&quest_data->list[index_quest][2]);
    for (; quest_data->list[index_quest][i] != ' '; i++)
        ;
    return i + 1;
}

int setup_go_zone(quest_list_t *quest_data, int index_quest)
{
    int i = 2;

    quest_data->quests[index_quest].state = 0;
    quest_data->quests[index_quest].quest_type = 2;
    quest_data->quests[index_quest].go_zone.zone_id =
        my_getnbr(&quest_data->list[index_quest][2]);
    for (; quest_data->list[index_quest][i] != ' '; i++)
        ;
    return i + 1;
}

int setup_talk_to_pnj(quest_list_t *quest_data, int index_quest)
{
    int i = 2;

    quest_data->quests[index_quest].state = 0;
    quest_data->quests[index_quest].quest_type = 3;
    quest_data->quests[index_quest].talk_to_pnj.pnj_id =
        my_getnbr(&quest_data->list[index_quest][2]);
    for (; quest_data->list[index_quest][i] != ' '; i++)
        ;
    return i + 1;
}

int setup_get_item(quest_list_t *quest_data, int index_quest)
{
    int i = 2;

    quest_data->quests[index_quest].state = 0;
    quest_data->quests[index_quest].quest_type = 4;
    quest_data->quests[index_quest].get_item.type_id =
        my_getnbr(&quest_data->list[index_quest][2]);
    for (; quest_data->list[index_quest][i] != ' '; i++)
        ;
    i++;
    quest_data->quests[index_quest].get_item.count =
        my_getnbr(&quest_data->list[index_quest][i]);
    for (; quest_data->list[index_quest][i] != ' '; i++)
        ;
    return i + 1;
}

void parse_quest_info(quest_list_t *quest_data, int index_quest)
{
    int i = 0;

    if (quest_data->quests[index_quest].quest_type < 1
        || quest_data->quests[index_quest].quest_type > 4)
        return;
    if (quest_data->quests[index_quest].quest_type == 1)
        i = setup_kill_monster(quest_data, index_quest);
    if (quest_data->quests[index_quest].quest_type == 2)
        i = setup_go_zone(quest_data, index_quest);
    if (quest_data->quests[index_quest].quest_type == 3)
        i = setup_talk_to_pnj(quest_data, index_quest);
    if (quest_data->quests[index_quest].quest_type == 4)
        i = setup_get_item(quest_data, index_quest);
    quest_data->quests[index_quest].context =
        my_strdup(quest_data->list[index_quest] + i);
}
