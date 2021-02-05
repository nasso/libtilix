/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Implementation of strncat.
*/

#include "my/cstr.h"

char *my_cstrncat(char *dest, const char *src, usize_t nb)
{
    usize_t len = my_cstrlen(dest);
    usize_t i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
