/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my_getnbr
*/

int operator(char const *str)
{
    int negative = 0;

    for (int i = 0; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            negative += 1;
    }
    if (0 != negative % 2) {
        return (-1);
    } else if (0 == negative % 2) {
        return (1);
    }
}

int my_getnbr(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] >= '0' && str[i] <= '9'
    || str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && str[i + 1] == '\0'
        || str[i] >= 'A' && str[i] <= 'Z' && str[i + 1] == '\0') {
            nb = nb * (str[i] - 48);
            return (nb);
        }
        if (str[i] >= '0' && str[i] <= '9') {
            nb = ((nb * 10) + str[i] - 48);
        } else if (nb > 2147483647 || nb < -2147483647) {
            return (0);
        }
    }
    nb = nb * operator(str);
    return (nb);
}
