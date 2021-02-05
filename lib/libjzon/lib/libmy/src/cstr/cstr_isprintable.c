/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Returns true if the given string contains only printable characters.
*/

#include "my/cstr.h"

static const char PRINTABLE_CHARS_START = 32;

bool my_cstr_isprintable(const char *str)
{
    for (usize_t i = 0; str[i] != '\0'; i++)
        if (str[i] < PRINTABLE_CHARS_START)
            return (false);
    return (true);
}
