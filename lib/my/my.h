/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

    #include <stdarg.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>

int my_strlen(char const *str);
void my_putstr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);
char *my_revstr(char *str);
int my_getnbr(char const *str);
void my_put_nbr_long(long nb);
long unsigned_number(long nb);
int my_len(int nb);
int get_num(char *s, va_list ap, int i, int nbf);
int my_putnbr_base(int nbr , char const *base);
long long my_putnbr_base_long(long long nbr , char const *base);
void display_base(char *str);
int basic_modulo(char *s, va_list ap, int i, char modulo);
int continuation(char *s, va_list ap, int i, char modulo);
int continuation2(char *s, va_list ap, int i, char modulo);
int format_modulo(char *s, va_list ap, int i, char modulo);
void my_printf(char *s, ...);
int my_getnbr(char const *str);
char **mem_alloc_2d_array(int nb_rows , int nb_cols);

#endif
