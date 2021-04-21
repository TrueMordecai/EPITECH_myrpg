/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    unsigned int nb = 0;
    int signe = 0;

    for (;str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            signe++;
    }
    for (;str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb = nb + (str[i] - 48);
    }
    if (nb > 2147483647 && signe % 2 == 0)
        return (0);
    if (nb > 2147483648 && signe % 2 == 1)
        return (0);
    if (signe % 2 == 0)
        return (nb);
    return (nb * -1);
}
