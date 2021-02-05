/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Reverses a string.
*/

#include "my/cstr.h"

static void swap_chars(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
}

char *my_cstrrev(char *str)
{
    usize_t len = my_cstrlen(str);
    usize_t half_len = len / 2 + (len % 2);

    for (usize_t i = 0; i < half_len; i++)
        swap_chars(&str[i], &str[len - i - 1]);
    return (str);
}
