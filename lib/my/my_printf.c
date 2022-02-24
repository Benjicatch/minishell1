/*
** EPITECH PROJECT, 2021
** disp_stdarg.c
** File description:
** disp_stdarg
*/
#include "my.h"

int number(char *s, va_list ap, int i)
{
    char *nb = malloc(sizeof(int));
    int nbf;
    int k = i;

    if (s[i + 1] <= '9' && s[i + 1] >= '0') {
        for (int j = 0; s[i + 1] <= '9' && s[i + 1] >= '0'; j++) {
            nb[j] = s[i + 1];
            i++;
        }
        nbf = my_getnbr(nb);
    }
    free(nb);
    i = get_num(s, ap, k, nbf);
    return i;
}

int continuation2(char *s, va_list ap, int i, char modulo)
{
    switch (modulo) {
        case 'S' : display_base(va_arg(ap, char *));
            i += 2;
            break;
    }
    return i;
}

int continuation(char *s, va_list ap, int i, char modulo)
{
    switch (modulo) {
        case 'u' : my_put_nbr(unsigned_number(va_arg(ap, int)));
            i += 2;
            break;
        case 'o' : my_putnbr_base(va_arg(ap, int), "01234567");
            i += 2;
            break;
        case 'x' : my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
            i += 2;
            break;
        case 'X' : my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
            i += 2;
            break;
        case 'p' : my_putstr("0x");
            my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
            i += 2;
            break;
    }
    i = continuation2(s, ap, i, modulo);
    return i;
}

int basic_modulo(char *s, va_list ap, int i, char modulo)
{
    switch (modulo) {
        case 'c' : my_putchar(va_arg(ap, int));
            i += 2;
            break;
        case 'd' :
        case 'i' : my_put_nbr(va_arg(ap, int));
            i += 2;
            break;
        case 's': my_putstr(va_arg(ap, char *));
            i += 2;
            break;
        case '%' : my_putchar('%');
            i += 2;
            break;
        case 'b' : my_putnbr_base(va_arg(ap, int), "01");
            i += 2;
            break;
    }
    i = continuation(s, ap, i, modulo);
    return i;
}

void my_printf(char *s, ...)
{
    va_list ap;
    char modulo = '0';

    va_start(ap, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%' || s[i] == '\\')
            modulo = s[i + 1];
        i = format_modulo(s, ap, i, modulo);
        i = basic_modulo(s, ap, i, modulo);
        modulo = '0';
        if (s[i] == '\0')
            break;
        if (s[i] == '%') {
            i--;
            continue;
        }
        my_putchar(s[i]);
    }
}
