/*
** EPITECH PROJECT, 2022
** exit.c
** File description:
** do_exit
*/
#include "minishell.h"

int check_num(char **name)
{
    int nb = 0;

    if (my_str_isnum(name[1]) == 0) {
        if (name[1][0] >= '0' && name[1][0] <= '9') {
            my_printf("exit: Badly formed number.\n");
        } else {
            my_printf("exit: Expression Syntax.\n");
        }
        nb = 1;
    }
    return nb;
}

int do_exit(char **av, char **env, char **name)
{
    int nb = 0;

    if (name[1] == NULL) {
        my_printf("exit\n");
        return 0;
    } else {
        nb = check_num(name);
        if (nb == 1)
            nb = mysh(av, env);
        my_printf("exit\n");
        return my_getnbr(name[1]);
    }
}
