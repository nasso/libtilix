/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_memcpy
*/

#include <string.h>
#include "my/my.h"

void *my_memcpy(void *dest, const void *src, usize_t n)
{
#if defined(MY_ALLOW_FUN_MEMCPY)
    memcpy(dest, src, (size_t) n);
#else
    while (n--)
        ((char*) dest)[n] = ((const char*) src)[n];
#endif
    return (dest);
}
