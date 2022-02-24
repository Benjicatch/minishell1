/*
** EPITECH PROJECT, 2022
** tests_exit.c
** File description:
** tests
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

static char *env[8] = {
"HOSTNAME=fedora",
"SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228",
"PWD=/home/bcolimard/Unix_System/minishell/B-PSU-101-NAN-1-1-minishell1-benjamin.colimard",
"LOGNAME=bcolimard",
"OLDPWD=/home/bcolimard",
"PATH=/home/bcolimard/.local/bin:/home/bcolimard/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin",
"HOME=/home/bcolimard",
NULL};

Test(do_exit, exit_no_arg, .init = redirect_all_stdout)
{
    char *av[1] = {"exit"};
    char *name[2] = {"exit", NULL};
    int nb = do_exit(av, env, name);

    cr_assert_eq(nb, 0);
    cr_assert_stdout_eq_str("exit\n");
}

Test(check_num, good_num, .init = redirect_all_stdout)
{
    char *name[2] = {"exit", "-45"};
    int nb = check_num(name);

    cr_assert_eq(nb, 0);
}

Test(check_num, good_num2, .init = redirect_all_stdout)
{
    char *name[2] = {"exit", "125"};
    int nb = check_num(name);

    cr_assert_eq(nb, 0);
}

Test(check_num, bad_num_alphanum, .init = redirect_all_stdout)
{
    char *name[2] = {"exit", "frevds84"};
    int nb = check_num(name);

    cr_assert_eq(nb, 1);
    cr_assert_stdout_eq_str("exit: Expression Syntax.\n");
}

Test(check_num, bad_num_first_num, .init = redirect_all_stdout)
{
    char *name[2] = {"exit", "84fzegr"};
    int nb = check_num(name);

    cr_assert_eq(nb, 1);
    cr_assert_stdout_eq_str("exit: Badly formed number.\n");
}

Test(do_exit, exit_arg, .init = redirect_all_stdout)
{
    char *av[1] = {"exit"};
    char *name[2] = {"exit", "125"};
    int nb = do_exit(av, env, name);

    cr_assert_eq(nb, 125);
    cr_assert_stdout_eq_str("exit\n");
}
