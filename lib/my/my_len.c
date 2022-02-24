/*
** EPITECH PROJECT, 2021
** my_nblen.c
** File description:
** return len number
*/
#include "my.h"

int my_len(int nb)
{
    int a = 0;
    int i = 0;
    int rest = 0;
    int neg = nb;
    char *str = malloc(sizeof(int));

    if (nb < 0)
        nb = nb * -1;
    if (nb == 0)
        return (1);
    for (; nb != 0; i++) {
        rest = nb % 10;
        nb = nb / 10;
        str[i] = rest + 48;
    }
    str[i] = '\0';
    for (int j = 0; str[j] != '\0'; j++)
        a++;
    free(str);
    return (a);
}
