/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my_strlen
*/
#include <unistd.h>

int my_strlen(char const *str)
{
    int a = 0;

    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        a += 1;
    }
    return (a);
}
