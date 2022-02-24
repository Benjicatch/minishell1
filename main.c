/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/
#include "minishell.h"

int main(int ac, char **av, char **env)
{
    int nb = 0;

    if (ac == 1) {
        nb = mysh(av, env);
    } else {
        return 84;
    }
    return nb;
}
