/*
** EPITECH PROJECT, 2022
** tests_cd.c
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

// Test(do_cd, no_args, .init = redirect_all_stdout)
// {
//     char *str[2] = {"cd", NULL};
//     params param = init_params("Hello", str, 0);

//     do_cd(param);
//     display_env(param);
//     cr_assert_stdout_eq_str(
//     "HOSTNAME=fedora\n"
//     "SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228\n"
//     "PWD=/home/bcolimard"
//     "LOGNAME=bcolimard\n"
//     "OLDPWD=/home/bcolimard\n"
//     "PATH=/home/bcolimard/.local/bin:/home/bcolimard/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin\n"
//     "HOME=/home/bcolimard\n");
// }
