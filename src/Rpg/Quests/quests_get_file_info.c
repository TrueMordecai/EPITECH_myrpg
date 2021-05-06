/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper2-paul-antoine.salmon
** File description:
** get_file_info.c
*/

#include <libmy/ascii/ascii.h>
#include <libmy/io.h>

#include "Rpg/Quests/quests.h"

int get_file_id(char const *file_path)
{
    int file_id = 0;

    file_id = open(file_path, O_RDONLY);
    if (file_id == -1) {
        my_putstr("Error : this file doesn't exist");
        return (-1);
    }
    return (file_id);
}

int get_file_size(char const *file_path)
{
    struct stat file;

    if (stat(file_path, &file) == -1) {
        my_putstr("Error : stat fail");
        return (-1);
    }
    return (file.st_size);
}

char *my_file_content_to_str(char const *file_path)
{
    int file_id = get_file_id(file_path);
    long size = get_file_size(file_path);
    char *file_content = malloc(sizeof(char) * (size + 2));

    if (file_id == -1)
        return (NULL);
    file_content[size] = '\0';
    if (read(file_id, file_content, size) == -1) {
        my_putstr("Error : read fail");
        return (NULL);
    }
    return (file_content);
}

int get_nb_line(char *filecontent)
{
    int count = 0;

    for (size_t i = 0; i < (my_strlen(filecontent) + 1); i++) {
        if (filecontent[i] == '\n' || filecontent[i] == '\0')
            count++;
    }
    return (count);
}
