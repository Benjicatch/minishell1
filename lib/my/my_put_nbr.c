/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** my_put_nbr
*/
#include "my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    } else if (nb == -2147483648) {
        my_putstr("2147483648");
    }
}

void my_put_nbr_long(long nb)
{
    char *str = malloc(sizeof(long));

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    for (int i = 0; nb != 0; i++) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    my_revstr(str);
    my_putstr(str);
    if (nb == -2147483648) {
        my_putstr("2147483648");
    }
}

long unsigned_number(long nb)
{
    if (nb < 0) {
        nb = nb * -1;
    }
    return nb;
}
