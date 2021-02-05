/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_memmove
*/

#include <string.h>
#include "my/my.h"

#ifndef MY_ALLOW_FUN_MEMMOVE
static void memcpy_from_start(void *dest, const void *src, size_t n)
{
    char *dest_c = dest;
    const char *src_c = src;

    while (n--)
        *(dest_c++) = *(src_c++);
}

static void memcpy_from_end(void *dest, const void *src, size_t n)
{
    char *dest_c = dest;
    const char *src_c = src;

    while (n--)
        dest_c[n] = src_c[n];
}
#endif
void *my_memmove(void *dest, const void *src, usize_t n)
{
#if defined(MY_ALLOW_FUN_MEMMOVE)
    memmove(dest, src, (size_t) n);
#else
    if (dest < src)
        memcpy_from_start(dest, src, n);
    else if (dest > src)
        memcpy_from_end(dest, src, n);
#endif
    return (dest);
}
