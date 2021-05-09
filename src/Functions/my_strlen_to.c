/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** strchr, but jankier
*/

int my_strlen_to(char *str, char end)
{
    int len = 0;

    if (!str)
        return 0;
    while (str[len] && str[len] != end)
        len++;
    return len;
}
