/*
** EPITECH PROJECT, 2022
** tests_project.c
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

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

params init_params(char *buffer, char **str, int nb)
{
    params parameters;

    if (nb == 0)
        parameters.env = env;
    parameters.path = take_path(check_env("PATH", parameters.env));
    parameters.logname = take_path(check_env("HOME", parameters.env));
    parameters.buffer = buffer;
    parameters.str = str;
    return parameters;
}

Test(verif_arg, have_an_arg)
{
    int nb = verif_arg("hello");

    cr_assert_eq(nb, 1);
}

Test(check_env, have_an_arg)
{
    char *str = check_env("HOME", env);

    cr_assert_str_eq(str, "HOME=/home/bcolimard");
}

Test(check_env, havent_an_arg)
{
    char *str = check_env("hello", env);

    cr_assert_null(str);
}

Test(take_path, take_all_path)
{
    char *str = take_path("SSH_AUTH_SOCK=/tmp/ssh-XXXXXXsV47a9/agent.1228");

    cr_assert_str_eq(str, "/tmp/ssh-XXXXXXsV47a9/agent.1228");
}

Test(take_var, take_all_var)
{
    char *str = take_var("SSH_ASKPASS=/usr/libexec/openssh/gnome-ssh-askpass");
    cr_assert_str_eq(str, "SSH_ASKPASS");
}

Test(nb_arg_env, take_max_env)
{
    int nb = nb_arg_env(env);

    cr_assert_eq(nb, 7);
}

Test(check_path, have_path, .init = redirect_all_stdout)
{
    char *str[2] = {"world", "hello"};
    params param = init_params("Hello", str, 0);
    int set = 0;
    int nb = check_path(param, set);

    cr_assert_eq(nb, 0);
}
