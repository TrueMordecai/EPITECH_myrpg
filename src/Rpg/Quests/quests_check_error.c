/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-andreas.leroux
** File description:
** quests_check_error.c
*/

#include <stddef.h>
#include "libmy/ascii.h"
#include "Rpg/rpg.h"

int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int verify_kill_quest(char *quest)
{
    if (quest[0] == '1')
        if (isnum(quest[4]) == 0 || quest[5] != ' ')
            return (-1);
    return (0);
}

int check_file_error(char **quests_list)
{
    for (int i = 0; quests_list[i] != NULL; i++) {
        if (my_strlen(quests_list[i]) < 5)
            return (-1);
        if (isnum(quests_list[i][0]) == 0 || isnum(quests_list[i][2]) == 0 || \
            quests_list[i][1] != ' ' || quests_list[i][3] != ' ')
            return (-1);
        if (quests_list[i][0] < '1' || quests_list[i][0] > '4')
            return (-1);
        if (verify_kill_quest(quests_list[i]) == -1)
            return (-1);
    }
    return (0);
}