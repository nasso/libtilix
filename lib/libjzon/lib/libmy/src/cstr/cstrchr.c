/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strchr, my_strrchr and my_strchrnul
*/

#include "my/cstr.h"

const char *my_cstrchr(const char *str, char c)
{
    while (*str && *str != c)
        str++;
    return (*str == c ? str : NULL);
}

const char *my_cstrrchr(const char *str, char c)
{
    const char *last_occurence = NULL;

    while (*str) {
        if (*str == c)
            last_occurence = str;
        str++;
    }
    return (last_occurence);
}

const char *my_cstrchrnul(const char *str, char c)
{
    while (*str && *str != c)
        str++;
    return (str);
}
