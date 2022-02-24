/*
** EPITECH PROJECT, 2022
** mem_alloc_2d_array.c
** File description:
** malloc char **
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows , int nb_cols)
{
    char **buffer = malloc(sizeof(char *) * (nb_rows + 1));

    for (int i = 0; i <= nb_rows; i++) {
        buffer[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    return buffer;
}
