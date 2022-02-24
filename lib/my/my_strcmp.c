/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp
*/
#include "my.h"

int my_strcmp(char const *s1 , char const *s2)
{
    int nb = 0;
    int len = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (len != len2)
        return 1;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] == '\0')
            nb += s2[i];
        else if (s2[i] == '\0')
            nb -= s1[i];
        else
            nb = nb + (s1[i] - s2[i]);
    }
    return (nb);
}
