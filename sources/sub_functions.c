/*
** EPITECH PROJECT, 2022
** sub_functions.c
** File description:
** sub_functions
*/
#include "minishell.h"

char *check_env(const char *res, char **env)
{
    char *var;
    int i = 0;

    for (; env[i] != NULL; i++) {
        var = take_var(env[i]);
        if (my_strcmp(res, var) == 0) {
            free(var);
            break;
        }
        free(var);
    }
    if (env[i] == NULL)
        return NULL;
    else
        return env[i];
}

char *take_path(char *env)
{
    char *res = malloc(my_strlen(env));
    int i = 0;
    int j = 0;

    while (env[i - 1] != '=')
        i++;
    for (; env[i] != '\0'; i++) {
        res[j] = env[i];
        j++;
    }
    res[j] = '\0';
    return res;
}

void free_all(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        free(str[i]);
    }
    free(str);
}

char *take_var(char const *env)
{
    int i = 0;
    int j = 0;
    char *res;

    while (env[i] != '=') {
        i++;
    }
    res = malloc(sizeof(char) * (i + 1));
    for (; j < i; j++) {
        res[j] = env[j];
    }
    res[j] = '\0';
    return res;
}

int nb_arg_env(char **env, char *value, int arg)
{
    int nb = 0;

    if (arg == 0) {
        for (int i = 0; env[i] != NULL; i++) {
            nb++;
        }
    } else {
        for (int i = 0; my_strcmp(env[i], value) != 0; i++) {
            nb++;
        }
    }
    return nb;
}
