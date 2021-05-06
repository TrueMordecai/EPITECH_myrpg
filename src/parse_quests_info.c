/*
** EPITECH PROJECT, 2021
** MyRPG - Quests
** File description:
** parse_quests_info.c
*/

#include "quests.h"

void setup_kill_monster(t_data *quest_data, int index_quest)
{
    int i = 2;
    int save;

    quest_data->quest[index_quest].state = 0;
    quest_data->quest[index_quest].quest_type = 1;
    quest_data->quest[index_quest].kill_monster.type_id =
        my_getnbr(&quest_data->quests_list[index_quest][2]);
    for (; quest_data->quests_list[index_quest][i] != ' '; i++)
        ;
    i++;
    quest_data->quest[index_quest].kill_monster.type_id =
        my_getnbr(&quest_data->quests_list[index_quest][2]);
    for (; quest_data->quests_list[index_quest][i] != ' '; i++)
        ;
    i++;
    quest_data->quest[index_quest].context =
        &quest_data->quests_list[index_quest][i];
}

void setup_go_zone(t_data *quest_data, int index_quest)
{
    int i = 2;

    quest_data->quest[index_quest].state = 0;
    quest_data->quest[index_quest].quest_type = 2;
    quest_data->quest[index_quest].go_zone.zone_id =
        my_getnbr(&quest_data->quests_list[index_quest][2]);
    for (; quest_data->quests_list[index_quest][i] != ' '; i++)
        ;
    i++;
    quest_data->quest[index_quest].context =
        &quest_data->quests_list[index_quest][i];
}

void setup_talk_to_pnj(t_data *quest_data, int index_quest)
{
    int i = 2;

    quest_data->quest[index_quest].state = 0;
    quest_data->quest[index_quest].quest_type = 3;
    quest_data->quest[index_quest].talk_to_pnj.pnj_id =
        my_getnbr(&quest_data->quests_list[index_quest][2]);
    for (; quest_data->quests_list[index_quest][i] != ' '; i++)
        ;
    i++;
    quest_data->quest[index_quest].context =
        &quest_data->quests_list[index_quest][i];
}

void setup_get_item(t_data *quest_data, int index_quest)
{
    int i = 2;
    int save;

    quest_data->quest[index_quest].state = 0;
    quest_data->quest[index_quest].quest_type = 4;
    quest_data->quest[index_quest].get_item.type_id =
        my_getnbr(&quest_data->quests_list[index_quest][2]);
    for (; quest_data->quests_list[index_quest][i] != ' '; i++)
        ;
    i++;
    quest_data->quest[index_quest].get_item.count =
        my_getnbr(&quest_data->quests_list[index_quest][i]);
    for (; quest_data->quests_list[index_quest][i] != ' '; i++)
        ;
    i++;
    quest_data->quest[index_quest].context =
        &quest_data->quests_list[index_quest][i];
}

void parse_quest_info(t_data *quest_data, int index_quest)
{
    if (quest_data->quest[index_quest].quest_type == 1)
        setup_kill_monster(quest_data, index_quest);
    if (quest_data->quest[index_quest].quest_type == 2)
        setup_go_zone(quest_data, index_quest);
    if (quest_data->quest[index_quest].quest_type == 3)
        setup_talk_to_pnj(quest_data, index_quest);
    if (quest_data->quest[index_quest].quest_type == 4)
        setup_get_item(quest_data, index_quest);
}
