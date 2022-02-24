/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' && str[i] != '\n' || str[i] > '9' &&
        str[i] != '\n') && str[i] != '-')
            return 0;
    }
    return 1;
}
