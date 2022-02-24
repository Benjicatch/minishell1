/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/
#include "my.h"

int while_space(char const *str, int i)
{
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
        i++;
        if (str[i] == '\0')
            return i;
    }
    return i;
}

int nb_words(char const *str)
{
    int max = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            i = while_space(str, i);
            max++;
        }
    }
    return max;
}

int max_word(char const *str)
{
    int max = 0;
    int verif = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        verif++;
        if (max < verif)
            max = verif;
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            i = while_space(str, i);
            verif = 0;
        }
    }
    return max;
}

char **add_end(char **dest, int nb, int letter)
{
    dest[nb][letter] = '\0';
    if (dest[nb][0] == '\0') {
        dest[nb] = NULL;
        return dest;
    }
    dest[nb + 1] = NULL;
    return dest;
}

char **my_str_to_word_array(char const *str)
{
    int malloc_size[2] = {nb_words(str), max_word(str)};
    char **dest = mem_alloc_2d_array(malloc_size[0], malloc_size[1]);
    int nb = 0;
    int letter = 0;
    int j = while_space(str, 0);

    for (int i = j; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            i = while_space(str, i);
            dest[nb][letter] = '\0';
            nb += 1;
            i--;
            letter = 0;
            continue;
        }
        dest[nb][letter] = str[i];
        letter += 1;
    }
    dest = add_end(dest, nb, letter);
    return (dest);
}
