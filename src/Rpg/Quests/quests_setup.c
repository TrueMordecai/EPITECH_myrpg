/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper2-paul-antoine.salmon
** File description:
** setup.c
*/

#include "Rpg/Quests/quests.h"

void dup_line(char **map, char *file_content, int line, int index)
{
    int j = 0;

    for (; file_content[index] != '\n' && file_content[index] != '\0';
         j++, index++) {
        map[line][j] = file_content[index];
    }
    map[line][j] = '\0';
}

char **str_file_to_array(char **map, char *file_content)
{
    int j = 0;
    int line = 0;
    int nb_line = get_nb_line(file_content);

    map = malloc(sizeof(char *) * (nb_line + 1));
    for (int i = 0; line < nb_line; i++, j++) {
        if (line == 0 && i == 0)
            j++;
        if (file_content[i] == '\n' || file_content[i] == '\0') {
            map[line] = malloc(sizeof(char) * (j + 1));
            dup_line(map, file_content, line, i - j + 1);
            j = 0;
            line++;
        }
    }
    map[line] = NULL;
    return (map);
}

int setup_data(quest_list_t *file_info)
{
    char *file_content = my_file_content_to_str(file_info->filepath);

    file_info->file_size = get_file_size(file_info->filepath);
    file_info->list = str_file_to_array(file_info->list, file_content);
    free(file_content);
    return (0);
}
