/*
** EPITECH PROJECT, 2022
** help.c
** File description:
** display the help
*/
#include "minishell.h"

void check(int wstat)
{
    if (wstat == 0)
        my_printf("\n$> ");
}

void handler(int signum)
{
    int wstat = 0;

    if (signum == SIGINT) {
        if (getpid() == 0) {
            kill(0, SIGINT);
        } else {
            waitpid(-1, &wstat, 0);
            check(wstat);
        }
    }
}

void check_core(int wstatus)
{
    if (WCOREDUMP(wstatus)) {
        my_printf(" (core dumped)\n");
    } else {
        my_printf("\n");
    }
}

void what_error(int wstatus)
{
    switch (wstatus) {
        case 139:
            my_printf("%s", strsignal(SIGSEGV));
            check_core(wstatus);
            break;
        case 136:
            my_printf("Floating exception");
            check_core(wstatus);
            break;
        default:
            break;
    }
}
