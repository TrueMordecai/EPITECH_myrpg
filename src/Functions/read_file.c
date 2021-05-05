/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** read_file
*/

#include <libmy/io.h>
#include <libmy/printf.h>
#include <stdlib.h>

char *read_file(char const *path, size_t *file_size)
{
    my_iostream_t file;
    char *file_content;

    if (my_fopen(path, "r", &file)
        || my_fset_buffer(malloc(1024), 1024, &free, &file)) {
        my_fprintf(MY_STDERR, "Cannot open file: %#s\n", path);
        return NULL;
    }
    file_content = my_fread_to_string(SIZE_MAX, file_size, &file);
    if (file_content == NULL)
        my_fprintf(MY_STDERR, "Cannot read file: %#s\n", path);
    my_fclose(&file);
    my_ffree(&file);
    return file_content;
}