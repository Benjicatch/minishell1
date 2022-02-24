/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** my_putstr
*/
void my_putchar(char c);

void my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i]; i ++) {
        my_putchar(str[i]);
    }
}
