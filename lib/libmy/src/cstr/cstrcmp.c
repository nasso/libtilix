/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Implementation of strcmp.
*/

#include "my/cstr.h"

int my_cstrcmp(const char *s1, const char *s2)
{
    if (s1 == s2)
        return (0);
    for (usize_t i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
        if (s1[i] - s2[i])
            return (s1[i] - s2[i]);
    return (0);
}

bool my_cstreq(const char *s1, const char *s2)
{
    if (s1 == s2)
        return (true);
    while (*s1 == *s2 && *s1 != '\0') {
        s1++;
        s2++;
    }
    return (*s1 == *s2);
}
