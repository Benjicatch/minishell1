/*
** EPITECH PROJECT, 2022
** unsetenv.c
** File description:
** do_unsetenv.c
*/
#include "minishell.h"

int if_env_same(params parameters, char *var, int i, int j)
{
    if (my_strcmp(var, parameters.str[1]) == 0) {
        for (j = i; parameters.env[j] != NULL; j++) {
            parameters.env[j] = parameters.env[j + 1];
        }
        parameters.env[j] = NULL;
        return 1;
    }
    return 0;
}

void do_unsetenv(params parameters)
{
    char *var;
    int j = 0;
    int check = 0;

    if (parameters.str[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 0; parameters.env[i] != NULL; i++) {
        var = take_var(parameters.env[i]);
        check = if_env_same(parameters, var, i, j);
        if (check == 1) {
            free(var);
            break;
        }
        free(var);
    }
}
