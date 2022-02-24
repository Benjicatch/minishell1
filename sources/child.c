/*
** EPITECH PROJECT, 2022
** child.c
** File description:
** functions for child
*/
#include "minishell.h"

int check_access(params param, struct stat st, int res)
{
    if (access(param.str[0], F_OK) == 0 && st.st_mode & S_IXOTH &&
    opendir(param.str[0]) == NULL) {
        res = execve(param.str[0], param.str, param.env);
    } else {
        if (access(param.str[0], F_OK) == 0 &&
        (param.str[0][0] == '.' || param.str[0][0] == '/')) {
            my_printf("%s: Permission denied.\n", param.str[0]);
            res = 1;
        } else {
            my_printf("%s: Command not found.\n", param.str[0]);
            res = 1;
        }
    }
    return res;
}

int search_exec(char *add_slash, char *travel_path, int res, params param)
{
    char *concatene;
    struct stat st;

    for (int i = 0; travel_path != NULL; i++) {
        concatene = my_strcat(add_slash, param.str[0]);
        if (access(concatene, F_OK) == 0) {
            res = execve(concatene, param.str, param.env);
        }
        travel_path = strtok(NULL, ":");
        if (travel_path != NULL)
            add_slash = my_strcat(travel_path, "/");
        free(concatene);
    }
    stat(param.str[0], &st);
    res = check_access(param, st, res);
    return res;
}

void exec_child(params param)
{
    int child = 0;
    int res = 0;
    char *travel_path;
    char *add_slash;

    travel_path = strtok(param.path, ":");
    add_slash = my_strcat(travel_path, "/");
    child = fork();
    if (child == 0) {
        res = search_exec(add_slash, travel_path, res, param);
        free(add_slash);
        exit(res);
    }
}

int check_path(params param, int set)
{
    static int verif = 0;

    if (check_env("PATH", param.env) == NULL && verif == 0) {
        do_setenv("PATH", "usr/local/bin:/usr/bin:/bin:"
        "/usr/local/sbin:/usr/sbin", param.env);
        param.path = take_path(check_env("PATH", param.env));
        set = 1;
    } else if (my_strlen(param.path) == 0) {
        verif = 1;
        my_printf("%s: Command not found.\n", param.str[0]);
        return 0;
    }
    exec_child(param);
    return set;
}

int doing_child(params param)
{
    int wstatus[2] = {0, 0};

    if (my_strcmp("setenv", param.str[0]) == 0) {
        if (param.str[1] == NULL)
            display_env(param);
        else
            do_setenv(param.str[1], param.str[2], param.env);
    } else
        wstatus[1] = check_path(param, wstatus[1]);
    waitpid(-1, &wstatus[0], 0);
    if (wstatus[1] == 1) {
        param.str[1] = "PATH";
        param.str[2] = NULL;
        do_unsetenv(param);
        param.str[1] = NULL;
        free(param.path);
    }
    what_error(wstatus[0]);
    return wstatus[0];
}
