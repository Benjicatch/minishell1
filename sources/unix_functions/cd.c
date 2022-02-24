/*
** EPITECH PROJECT, 2022
** cd.c
** File description:
** do_cd
*/
#include "minishell.h"

path_cd no_arguments(params parameters, path_cd all_path)
{
    getcwd(all_path.old, sizeof(all_path.old));
    if (parameters.logname == NULL) {
        my_printf("cd: No home directory.\n");
    }
    chdir(parameters.logname);
    getcwd(all_path.res, sizeof(all_path.res));
    if (check_env("PWD", parameters.env) != 0)
        do_setenv("PWD", all_path.res, parameters.env);
    return all_path;
}

path_cd have_path(params parameters, path_cd all_path)
{
    getcwd(all_path.old, sizeof(all_path.old));
    if (chdir(parameters.str[1]) == -1) {
        my_printf("%s: Not a directory.\n", parameters.str[1]);
        return all_path;
    }
    getcwd(all_path.res, sizeof(all_path.res));
    if (check_env("PWD", parameters.env) != 0) {
        do_setenv("PWD", all_path.res, parameters.env);
    }
    return all_path;
}

path_cd negative_argument(params parameters, path_cd all_path)
{
    int i = 0;

    chdir(all_path.old);
    for (; all_path.res[i] != '\0'; i++) {
        all_path.old[i] = all_path.res[i];
    }
    all_path.old[i] = '\0';
    getcwd(all_path.res, sizeof(all_path.res));
    if (check_env("PWD", parameters.env) != 0)
        do_setenv("PWD", all_path.res, parameters.env);
    return all_path;
}

void do_cd(params parameters)
{
    static path_cd all_path;
    int check;

    if (parameters.str[1] == NULL || my_strcmp(parameters.str[1], "~") == 0) {
        all_path = no_arguments(parameters, all_path);
        return;
    }
    if (my_strcmp(parameters.str[1], "-") == 0) {
        if (all_path.old != NULL)
            all_path = negative_argument(parameters, all_path);
    } else {
        check = access(parameters.str[1], F_OK);
        if (check == -1) {
            my_printf("%s: Not such file or directory.\n", parameters.str[1]);
            return;
        }
        all_path = have_path(parameters, all_path);
    }
}
