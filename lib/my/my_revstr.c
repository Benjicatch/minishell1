/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int nb;
    char dest;
    int a;

    a = 0;
    nb = my_strlen(str) - 1;
    for (int i = 0; a < nb; i++) {
        dest = str[a];
        str[a] = str[nb];
        str[nb] = dest;
        a += 1;
        nb -= 1;
    }
    return (str);
}
