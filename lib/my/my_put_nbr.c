/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** put nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    unsigned int nbr;

    if (nb < 0) {
        my_putchar('-');
        nbr = nb * -1;
    }
    else
        nbr = nb;
    if (nbr >= 10)
        my_put_nbr(nbr / 10);
    my_putchar(nbr % 10 + 48);

    return (0);
}
