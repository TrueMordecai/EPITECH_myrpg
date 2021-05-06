/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** rev une string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char temp;
    int length;

    if (str == 0)
        return (str);
    while (str[j])
        j++;
    length = j;
    while (i < length / 2) {
        temp = str[i];
        str[i] = str[j - 1];
        str[j - 1] = temp;
        i++;
        j--;
    }
    return (str);
}
