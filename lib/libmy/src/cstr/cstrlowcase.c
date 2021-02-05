/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Makes the given string lowercase.
*/

#include "my/cstr.h"

static const char UPPER_TO_LOWER_OFFSET = 'a' - 'A';

char *my_cstrlowcase(char *str)
{
    for (usize_t i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += UPPER_TO_LOWER_OFFSET;
    return (str);
}
