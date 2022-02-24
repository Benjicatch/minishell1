/*
** EPITECH PROJECT, 2021
** my_putnbr_base.c
** File description:
** return number convert in the base asked
*/
#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);
    char *str = malloc(sizeof(int));
    int rest = 0;
    int neg = nbr;
    int i = 0;

    if (nbr < 0)
        nbr = nbr * -1;
    for (; nbr != 0; i++) {
        rest = nbr % len;
        nbr = nbr / len;
        str[i] = rest + base[rest] - rest;
    }
    if (neg < 0)
        str[i] = '-';
    my_revstr(str);
    my_putstr(str);
    free(str);
}

long long my_putnbr_base_long(long long nbr, char const *base)
{
    long long len = my_strlen(base);
    char *str = malloc(sizeof(long long));
    long long rest = 0;
    long long neg = nbr;
    long long i = 0;

    if (nbr < 0)
        nbr = nbr * -1;
    for (; nbr != 0; i++) {
        rest = nbr % len;
        nbr = nbr / len;
        str[i] = rest + base[rest] - rest;
    }
    if (neg < 0)
        str[i] = '-';
    my_revstr(str);
    my_putstr(str);
    free(str);
}
