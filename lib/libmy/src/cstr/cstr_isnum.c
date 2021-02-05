/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Returns true if the given string contains only digits.
*/

#include "my/cstr.h"

bool my_cstr_isnum(const char *str)
{
    for (usize_t i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}
