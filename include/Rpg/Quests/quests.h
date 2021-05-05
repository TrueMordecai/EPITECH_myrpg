/*
** EPITECH PROJECT, 2021
** MyRPG - Quests
** File description:
** quests.h
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef INCLUDE_H_
    #define INCLUDE_H_

typedef struct talk_to_pnj {
    int pnj_id;
} talk_to_pnj_t;

typedef struct kill_monster {
    int count;
    int type_id;
} kill_monster_t;

typedef struct get_item {
    int count;
    int type_id;
} get_item_t;

typedef struct go {
    int zone_id;
} go_t;

typedef struct quest {
    char *context;
    int quest_type;
    union {
        kill_monster_t kill_monster;
        go_t go_zone;
        talk_to_pnj_t talk_to_pnj;
        get_item_t get_item;
    };
    int state;
} quest_t;

typedef struct quests {
    char *filepath;
    char **list;
    quest_t *quests;
    int file_size;
} quest_list_t;

int get_file_id(char const *file_path);

int get_file_size(char const *file_path);

char *my_file_content_to_str(char const *file_path);

int get_nb_line(char *filecontent);

int setup_data(quest_list_t *file_info);

int quests(char *filepath, int iteration);

void parse_quest_info(quest_list_t *quest_data, int index_quest);

#endif