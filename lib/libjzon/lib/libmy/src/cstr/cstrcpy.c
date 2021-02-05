/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Implementation of strcpy
*/

#include "my/cstr.h"

char *my_cstrcpy(char *dest, const char *src)
{
    usize_t i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
