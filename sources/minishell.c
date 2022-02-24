/*
** EPITECH PROJECT, 2022
** minishell.c
** File description:
** minishell
*/
#include "minishell.h"

int verif_arg(char *buffer)
{
    int check = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\t') {
            check = 1;
        }
    }
    return check;
}

int choose_function(char **str, char **env)
{
    static params parameters;
    FuncPtr ptr_function[] = {do_cd, do_unsetenv, display_env};
    char *name_function[] = {"cd", "unsetenv", "env"};
    int verif_found = 0;

    parameters.env = env;
    parameters.str = str;
    if (check_env("HOME", parameters.env) != NULL)
        parameters.logname = take_path(check_env("HOME", parameters.env));
    if (check_env("PATH", env) != NULL)
        parameters.path = take_path(check_env("PATH", parameters.env));
    for (int i = 0; i < 3; i++) {
        if (my_strcmp(name_function[i], str[0]) == 0) {
            ptr_function[i](parameters);
            verif_found = 1;
        }
    }
    if (verif_found == 0)
        verif_found = doing_child(parameters);
    return verif_found;
}

int exit_or_choose(char **av, char **env, char *buffer)
{
    char **name;
    int nb = 0;

    name = my_str_to_word_array(buffer);
    if (my_strcmp("exit", name[0]) == 0) {
        nb = do_exit(av, env, name);
        free_all(name);
        exit(nb);
    } else {
        nb = choose_function(name, env);
    }
    free_all(name);
    return nb;
}

int mysh(char **av, char **env)
{
    ssize_t check;
    char *buffer = NULL;
    int res = 0;

    while (1) {
        signal(SIGINT, handler);
        if (isatty(0) == 1)
            my_printf("$> ");
        check = getline(&buffer, &(size_t){0}, stdin);
        if (check == -1)
            return 0;
        check = verif_arg(buffer);
        if (check == 0)
            continue;
        res = exit_or_choose(av, env, buffer);
    }
    free(buffer);
    return res;
}
