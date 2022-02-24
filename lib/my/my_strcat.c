/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** my_strcat
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int nb = my_strlen(dest) + my_strlen(src);
    int j = 0;
    int i = 0;
    int check = my_strlen(dest);
    char *final = malloc(sizeof(char) * (nb + 1));

    for (; i < nb; i++) {
        final[i] = dest[i];
        if (i >= check) {
            final[i] = src[j];
            j += 1;
        }
    }
    final[i] = '\0';
    return final;
}
