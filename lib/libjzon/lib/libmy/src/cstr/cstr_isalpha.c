/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Returns true if the given string contains only alphabetic characters.
*/

#include "my/cstr.h"

static bool my_isalpha(char c)
{
    bool val = false;

    val |= c >= 'a' && c <= 'z';
    val |= c >= 'A' && c <= 'Z';
    return (val);
}

bool my_cstr_isalpha(char const* str)
{
    for (usize_t i = 0; str[i] != '\0'; i++)
        if (!my_isalpha(str[i]))
            return (false);
    return (true);
}
