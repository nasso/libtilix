/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Makes the given string uppercase.
*/

#include "my/cstr.h"

static const char LOWER_TO_UPPER_OFFSET = 'A' - 'a';

char *my_cstrupcase(char *str)
{
    for (usize_t i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += LOWER_TO_UPPER_OFFSET;
    return (str);
}
