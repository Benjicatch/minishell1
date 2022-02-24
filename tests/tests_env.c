/*
** EPITECH PROJECT, 2022
** tests_env.c
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

Test(do_unsetenv, no_args, .init = redirect_all_stdout)
{
    char *str[2] = {"unsetenv", NULL};
    params param = init_params("Hello", str, 0);

    do_unsetenv(param);
    cr_assert_stdout_eq_str("unsetenv: Too few arguments.\n");
}

Test(display_env, display_good, .init = redirect_all_stdout)
{
    char *str[2] = {"unsetenv", NULL};
    params param = init_params("Hello", str, 0);

    display_env(param);
    cr_assert_stdout_eq_str(
    "HOSTNAME=fedora\n"
    "SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228\n"
    "PWD=/home/bcolimard/Unix_System/minishell/B-PSU-101-NAN-1-1-minishell1-benjamin.colimard\n"
    "LOGNAME=bcolimard\n"
    "OLDPWD=/home/bcolimard\n"
    "PATH=/home/bcolimard/.local/bin:/home/bcolimard/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin\n"
    "HOME=/home/bcolimard\n");
}

Test(display_env, no_display, .init = redirect_all_stdout)
{
    char *str[3] = {"unsetenv", "PWD", NULL};
    params param = init_params("Hello", str, 0);

    display_env(param);
    cr_assert_stdout_eq_str("env: 'PWD': No such file or directory\n");
}

Test(do_unsetenv, no_existant_args, .init = redirect_all_stdout)
{
    char *str[3] = {"unsetenv", "hello", NULL};
    params param = init_params("Hello", str, 0);

    do_unsetenv(param);
    param.str[1] = NULL;
    display_env(param);
    cr_assert_stdout_eq_str(
    "HOSTNAME=fedora\n"
    "SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228\n"
    "PWD=/home/bcolimard/Unix_System/minishell/B-PSU-101-NAN-1-1-minishell1-benjamin.colimard\n"
    "LOGNAME=bcolimard\n"
    "OLDPWD=/home/bcolimard\n"
    "PATH=/home/bcolimard/.local/bin:/home/bcolimard/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin\n"
    "HOME=/home/bcolimard\n");
}

Test(do_unsetenv, existant_args, .init = redirect_all_stdout)
{
    char *str[3] = {"unsetenv", "PWD", NULL};
    params param = init_params("Hello", str, 0);

    do_unsetenv(param);
    param.str[1] = NULL;
    display_env(param);
    cr_assert_stdout_eq_str(
    "HOSTNAME=fedora\n"
    "SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228\n"
    "LOGNAME=bcolimard\n"
    "OLDPWD=/home/bcolimard\n"
    "PATH=/home/bcolimard/.local/bin:/home/bcolimard/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin\n"
    "HOME=/home/bcolimard\n");
}

Test(if_not_in_env, add_in_env, .init = redirect_all_stdout)
{
    char *str[3] = {"unsetenv", "PWD", NULL};
    params param = init_params("Hello", str, 0);

    if_not_in_env("hello", "world", param.env);
    param.str[1] = NULL;
    display_env(param);
    cr_assert_stdout_eq_str(
    "HOSTNAME=fedora\n"
    "SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228\n"
    "PWD=/home/bcolimard/Unix_System/minishell/B-PSU-101-NAN-1-1-minishell1-benjamin.colimard\n"
    "LOGNAME=bcolimard\n"
    "OLDPWD=/home/bcolimard\n"
    "PATH=/home/bcolimard/.local/bin:/home/bcolimard/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin\n"
    "HOME=/home/bcolimard\n"
    "hello=world\n");
}

Test(if_not_in_env, add_in_env_empty, .init = redirect_all_stdout)
{
    char *str[3] = {"unsetenv", "PWD", NULL};
    params param = init_params("Hello", str, 0);

    if_not_in_env("hello", NULL, param.env);
    param.str[1] = NULL;
    display_env(param);
    cr_assert_stdout_eq_str(
    "HOSTNAME=fedora\n"
    "SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228\n"
    "PWD=/home/bcolimard/Unix_System/minishell/B-PSU-101-NAN-1-1-minishell1-benjamin.colimard\n"
    "LOGNAME=bcolimard\n"
    "OLDPWD=/home/bcolimard\n"
    "PATH=/home/bcolimard/.local/bin:/home/bcolimard/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin\n"
    "HOME=/home/bcolimard\n"
    "hello=\n");
}

Test(do_setenv, add_in_env_empty, .init = redirect_all_stdout)
{
    char *str[3] = {"unsetenv", "PWD", NULL};
    params param = init_params("Hello", str, 0);

    do_setenv("hello", NULL, param.env);
    param.str[1] = NULL;
    display_env(param);
    cr_assert_stdout_eq_str(
    "HOSTNAME=fedora\n"
    "SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228\n"
    "PWD=/home/bcolimard/Unix_System/minishell/B-PSU-101-NAN-1-1-minishell1-benjamin.colimard\n"
    "LOGNAME=bcolimard\n"
    "OLDPWD=/home/bcolimard\n"
    "PATH=/home/bcolimard/.local/bin:/home/bcolimard/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin\n"
    "HOME=/home/bcolimard\n"
    "hello=\n");
}

Test(error_case, error, .init = redirect_all_stdout)
{
    int nb = error_case("4dcezf");

    cr_assert_stdout_eq_str("setenv: Variable name must begin with a letter.\n");
    cr_assert_eq(nb, 1);
}

Test(error_case, error_alphanumeric, .init = redirect_all_stdout)
{
    int nb = error_case("dce-zf");

    cr_assert_stdout_eq_str("setenv: Variable name must contain alphanumeric"
            " characters.\n");
    cr_assert_eq(nb, 1);
}

Test(error_case, no_error, .init = redirect_all_stdout)
{
    int nb = error_case("hello");

    cr_assert_eq(nb, 0);
}
