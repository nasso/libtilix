/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Returns true if the given string contains only lowercase letters.
*/

#include "my/cstr.h"

bool my_cstr_islower(const char *str)
{
    for (usize_t i = 0; str[i] != '\0'; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return (false);
    return (true);
}
