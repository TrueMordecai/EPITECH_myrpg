/*
** EPITECH PROJECT, 2020
** B-CPE-210-NAN-2-1-stumper2-paul-antoine.salmon
** File description:
** main.c
*/

#include "quests.h"

int detect_error(int argc, char **argv)
{
    if (argc > 3 || argc <= 2)
        return (-1);
    if (get_file_id(argv[1]) == -1)
        return (-1);
    if (my_getnbr(argv[2]) < 0)
        return (-1);
    return 0;
}

int main(int argc, char **argv)
{
    if (detect_error(argc, argv) == -1)
        return (84);
    if (quests(argv[1], my_getnbr(argv[2])) == -1)
        return (84);
    return 0;
}