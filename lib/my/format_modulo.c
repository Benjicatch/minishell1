/*
** EPITECH PROJECT, 2021
** format_modulo.c
** File description:
** type of format
*/
#include "my.h"

void modulo_l(char *s, va_list ap, int i, char modulo)
{
    switch (modulo) {
        case 'i' :
        case 'd' : my_put_nbr_long(va_arg(ap, long));
            break;
        case 'u' : my_put_nbr_long(unsigned_number(va_arg(ap, long)));
            break;
        case 'o' : my_putnbr_base_long(va_arg(ap, long), "01234567");
            break;
        case 'x' : my_putnbr_base_long(va_arg(ap, long), "0123456789abcdef");
            break;
        case 'X' : my_putnbr_base_long(va_arg(ap, long), "0123456789ABCDEF");
            break;
    }
}

int format_modulo(char *s, va_list ap, int i, char modulo)
{
    switch (modulo) {
        case 'l' : modulo = s[i + 2];
            modulo_l(s, ap, i + 1, modulo);
            i += 3;
            break;
    }
    return i;
}
