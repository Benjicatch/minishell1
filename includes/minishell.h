/*
** EPITECH PROJECT, 2022
** minishell.h
** File description:
** minishell
*/

#ifndef MINISHELL_H
    #define MINISHELL_H

    #include <stddef.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdbool.h>

typedef void (*FuncPtr)();

typedef void (*sighandler_t)(int);

typedef struct params_s {
    char **str;
    char **env;
    char *buffer;
    char *logname;
    char *path;
} params;

typedef struct check_old {
    char res[256];
    char old[256];
    char *swi;
} path_cd;

void my_printf(char *s, ...);
char **my_str_to_word_array(char const *str);
int my_strcmp(char const *s1 , char const *s2);
char *my_strcat(char *dest, char const *src);
void display_help(void);
int mysh(char **av, char **env);
void display_env(params parameters);
void free_all(char **str);
char *take_var(char const *env);
int exit_or_choose(char **av, char **env, char *buffer);
char *take_path(char *env);
char *check_env(const char *res, char **env);
int nb_arg_env(char **env, char *value, int arg);
int do_exit(char **av, char **env, char **name);
void do_cd(params parameters);
void do_unsetenv(params parameters);
int my_getnbr(char const *str);
void do_setenv(char *name, char const *value, char **env);
int my_strlen(char const *str);
int if_env_same(params parameters, char *var, int i, int j);
int my_str_isnum(char const *str);
int verif_arg(char *buffer);
int doing_child(params param);
int choose_function(char **str, char **env);
int check_path(params param, int set);
int check_num(char **name);
int error_case(char const *str);
void if_not_in_env(char const *name, char const *value, char **env);
void handler(int signum);
void what_error(int wstatus);

void redirect_all_stdout(void);
params init_params(char *buffer, char **str, int nb);

#endif
