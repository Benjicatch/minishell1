/*
** EPITECH PROJECT, 2022
** env.c
** File description:
** do_env
*/
#include "minishell.h"

void display_env(params parameters)
{
    if (parameters.str[1] != NULL) {
        my_printf("env: '%s': No such file or directory\n", parameters.str[1]);
        return;
    }
    for (int i = 0; parameters.env[i] != NULL; i++) {
        my_printf("%s\n", parameters.env[i]);
    }
}
