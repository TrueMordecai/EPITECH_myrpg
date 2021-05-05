/*
** EPITECH PROJECT, 2020
** Quêtes
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_talk_to_pnj
{
    int pnj_id;
} t_talk_to_pnj;

typedef struct s_kill_monster
{
    int count;
    int type_id;
} t_kill_monster;

typedef struct s_get_item
{
    int count;
    int type_id;
} t_get_item;

typedef struct s_go
{
    int zone_id;
} t_go;

typedef struct s_quest
{
    char *context;
    int quest_type;
    union
    {
        t_kill_monster kill_monster;
        t_go go_zone;
        t_talk_to_pnj talk_to_pnj;
        t_get_item get_item;
    };
    int state;
} t_quest;


typedef struct s_data
{
    char *filepath;
    char **quests_list;
    t_quest *quest;
    int file_size;
} t_data;


#endif