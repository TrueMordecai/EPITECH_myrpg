/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** racine carré
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb <= 0)
        return (0);
    while (i <= nb / 2) {
        if ((nb / i) == i)
            return (i);
        i++;
    }
    return (0);
}
