/*
** EPITECH PROJECT, 2021
** modulo_num.c
** File description:
** display when modulo have a number
*/
#include "my.h"

int get_num(char *s, va_list ap, int k, int nbf)
{
    if (s[k + 1] <= '9' && s[k + 1] >= '0' && s[k + my_len(nbf)] == 'd') {
        for (int j = 0; j < nbf; j++)
            my_putchar(' ');
        my_put_nbr_long(va_arg(ap, int));
        for (int j = 0; j <= my_len(nbf) + 1; j++) {
            k++;
        }
    }
    if (s[k + 1] <= '9' && s[k + 1] >= '0' && s[k + my_len(nbf) + 1] == 'i') {
        for (int j = 0; j < nbf; j++)
            my_putchar(' ');
        my_put_nbr_long(va_arg(ap, int));
        for (int j = 0; j <= my_len(nbf) + 1; j++) {
            k++;
        }
        return k;
    }
    return k;
}

void display_base(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 && str[i] > 9) {
            my_putchar('\\');
            my_putchar('0');
            my_putnbr_base(str[i], "01234567");
        } else if (str[i] <= 9 && str[i] >= 0) {
            my_putchar('\\');
            my_putstr("00");
            my_putnbr_base(str[i], "01234567");
        }
        if (str[i] >= 127) {
            my_putchar('\\');
            my_putnbr_base(str[i], "01234567");
        }
        my_putchar(str[i]);
    }
}
