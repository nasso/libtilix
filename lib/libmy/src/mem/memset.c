/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_memset
*/

#include <string.h>
#include <stdlib.h>
#include "my/my.h"

void *my_memset(void *s, u8_t c, usize_t n)
{
    if (s == NULL)
        return (NULL);
#if defined(MY_ALLOW_FUN_MEMSET)
    memset(s, (int) c, (size_t) n);
#else
    for (usize_t i = 0; i < n; i++)
        ((char*) s)[i] = c;
#endif
    return (s);
}
