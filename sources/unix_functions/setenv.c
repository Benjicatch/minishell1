/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** do_setenv
*/
#include "minishell.h"

int error_case(char const *str)
{
    if (str == NULL) {
        return 0;
    } else if (str[0] >= '0' && str[0] <= '9') {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'Z') &&
        (str[i] < 'a' || str[i] > 'z') && str[i] != '_') {
            my_printf("setenv: Variable name must contain alphanumeric"
            " characters.\n");
            return 1;
        }
    }
    return 0;
}

void if_not_in_env(char const *name, char const *value, char **env)
{
    int max = nb_arg_env(env, NULL, 0);
    int k = 0;

    k = error_case(name);
    if (k == 1)
        return;
    env[max] = malloc(my_strlen(name) + my_strlen(value));
    for (; name[k] != '\0'; k++)
        env[max][k] = name[k];
    env[max][k] = '=';
    k++;
    if (value == NULL) {
        env[max + 1] = NULL;
        return;
    }
    for (int i = 0; value[i] != '\0'; i++) {
        env[max][k] = value[i];
        k++;
    }
    env[max + 1] = NULL;
}

void do_setenv(char *name, char const *value, char **env)
{
    char *check_in = check_env(name, env);
    int nb;
    char *final;
    char *real_final;
    bool if_found = false;

    if (check_in != NULL) {
        nb = nb_arg_env(env, check_in, 1);
        final = my_strcat(name, "=");
        real_final = my_strcat(final, value);
        env[nb] = real_final;
        free(final);
        if_found = true;
    }
    if (if_found == false)
        if_not_in_env(name, value, env);
}
