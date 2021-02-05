/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Implementation of strncmp.
*/

#include "my/cstr.h"

i32_t my_cstrncmp(const char *s1, const char *s2, usize_t n)
{
    if (s1 == s2)
        return (0);
    for (usize_t i = 0; i < n && (s1[i] != '\0' || s2[i] != '\0'); i++)
        if (s1[i] - s2[i])
            return (s1[i] - s2[i]);
    return (0);
}
