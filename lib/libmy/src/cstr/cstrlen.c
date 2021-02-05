/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Returns the number of characters found in the string passed as parameter.
*/

#include "my/cstr.h"

usize_t my_cstrlen(const char *str)
{
    usize_t len = 0;

    if (str == NULL)
        return (0);
    while (str[len] != '\0')
        len++;
    return (len);
}
