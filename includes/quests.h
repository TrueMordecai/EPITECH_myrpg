/*
** EPITECH PROJECT, 2020
** Quêtes
** File description:
** quests.h
*/

#include "struct.h"
#include "my.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef INCLUDE_H_
#define INCLUDE_H_

int get_file_id(char const *file_path);

int get_file_size(char const *file_path);

char *my_file_content_to_str(char const *file_path);

int get_nb_line(char *filecontent);

int setup_data(t_data *file_info);

int quests(char *filepath, int iteration);

void parse_quest_info(t_data *quest_data, int index_quest);

#endif