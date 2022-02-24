/*
** EPITECH PROJECT, 2021
** int_char.c
** File description:
** transform int in char
*/
#include "my.h"

int if_not_null(char *tr, int nb, int rest, int i)
{
    for (; nb != 0; i++) {
        rest = nb % 10;
        tr[i] = rest + 48;
        nb /= 10;
    }
    return i;
}

char *int_char(int nb, char *tr)
{
    int i = 2;
    int rest = nb;
    int stay = nb;

    if (nb < 0)
        nb = nb * (-1);
    if (nb >= 0 && nb <= 9) {
        tr[0] = nb + 48;
        tr[3] = '\0';
        return tr;
    }
    i = if_not_null(tr, nb, rest, i);
    if (stay < 0)
        tr[i] = '-';
    tr[i] = '\0';
    my_revstr(tr);
    return tr;
}
